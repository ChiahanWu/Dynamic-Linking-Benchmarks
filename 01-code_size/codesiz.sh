#!/bin/bash

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

test_static_linking_codesiz() {
	sumsiz=0
	echo "static linking: "
	for i in $(seq 1 $maxfile)
	do
		gcc -o sout${i} main.c ./libvector.a
		filesiz=`ls -l sout${i} | awk '{print $5}'`
		sumsiz=$(($sumsiz + $filesiz))
		echo -n "$sumsiz \t"
	done
	echo "\n"

}


test_loadtime_dlk_codesiz() {
	sumsiz=0
	echo "loadtime dynamic linking: "
	for i in $(seq 1 $maxfile)
	do
		gcc -o ldout${i} main.c ./libvector.so
		filesiz=`ls -l ldout${i} | awk '{print $5}'`
		sumsiz=$(($sumsiz + $filesiz))
		echo -n "$sumsiz \t"
	done
	echo "\n"
}


test_runtime_dlk_codesiz() {
	sumsiz=0
	echo "runtime dynamic linking: "
	for i in $(seq 1 $maxfile)
	do
		gcc -rdynamic -o rdout${i} main2.c -ldl
		filesiz=`ls -l rdout${i} | awk '{print $5}'`
		sumsiz=$(($sumsiz + $filesiz))
		echo -n "$sumsiz \t"
	done
	echo "\n"
}


compilelib
test_static_linking_codesiz
test_loadtime_dlk_codesiz
test_runtime_dlk_codesiz
cleanall

