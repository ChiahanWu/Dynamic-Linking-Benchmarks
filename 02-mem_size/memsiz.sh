#!/bin/sh

maxfile=10 #maximun number of files to be tested

staticlib () {
	echo "Building static library..."
	gcc -c addvec.c multvec.c
	ar rcs libvector.a addvec.o multvec.o
}


sharedlib() {
	echo "Building shared library..."
	gcc -shared -fPIC -o libvector.so addvec.c multvec.c
}


compilelib() {
	echo "Cpmpiling library source code..."
	staticlib
	sharedlib
}


cleanall() {
	rm *.o
	rm libvector.a
	rm libvector.so
	for i in $(seq 1 $maxfile)
	do
		rm sout${i}
		rm ldout${i}
		rm rdout${i}
	done
}


test_static_linking_memsiz() {
	prememsiz=0
	echo "static linking: "
	for i in $(seq 1 $maxfile)
	do
		gcc -o sout${i} main.c ./libvector.a
		./sout${i} &
		sleep 0.5
		memsiz=`free | sed -n '2,2p' |awk '{print $3}'`
		submem=$(($memsiz-$prememsiz))
		prememsiz=$memsiz
		echo -n "$submem \t"

	done

	for i in $(seq 1 $maxfile)
	do
		kill -9 `ps -aux | grep "sout" | sed -n '1,1p' |awk '{print $2}'`
		sleep 0.2
	done

	echo "\n"


}


test_loadtime_dlk_memsiz() {
	prememsiz=0
	echo "loadtime dynamic linking: "
	for i in $(seq 1 $maxfile)
	do
		gcc -o ldout${i} main.c ./libvector.so
		./ldout${i} &
		sleep 0.5
		memsiz=`free | sed -n '2,2p' |awk '{print $3}'`
		submem=$(($memsiz-$prememsiz))
		prememsiz=$memsiz
		echo -n "$submem \t"
	done

	for i in $(seq 1 $maxfile)
	do
		kill -9 `ps -aux | grep "ldout" | sed -n '1,1p' |awk '{print $2}'`
		sleep 0.2
	done

	echo "\n"
}


test_runtime_dlk_memsiz() {
	prememsiz=0
	echo "runtime dynamic linking: "
	for i in $(seq 1 $maxfile)
	do
		gcc -rdynamic -o rdout${i} main2.c -ldl
		./rdout${i} &
		sleep 0.5
		memsiz=`free | sed -n '2,2p' |awk '{print $3}'`
		submem=$(($memsiz-$prememsiz))
		prememsiz=$memsiz
		echo -n "$submem \t"
	done

	for i in $(seq 1 $maxfile)
	do
		kill -9 `ps -aux | grep "rdout" | sed -n '1,1p' |awk '{print $2}'`
		sleep 0.2
	done

	echo "\n"
}


compilelib
test_static_linking_memsiz
test_loadtime_dlk_memsiz
test_runtime_dlk_memsiz
cleanall
