#!/bin/sh

dependencySharedlib() {
	echo "Building shared libraries which depends on each other..."
	gcc -shared -fPIC -o libmodC.so c.c 
	gcc -shared -fPIC -o libmodD.so d.c
	gcc -shared -fPIC -o libmodA.so a.c ./libmodC.so
	gcc -shared -fPIC -o libmodB.so b.c ./libmodD.so
}

sharedlib() {
	echo "Building shared libraries..."
	gcc -shared -fPIC -o libA.so a.c 
	gcc -shared -fPIC -o libB.so b.c
	gcc -shared -fPIC -o libC.so c.c 
	gcc -shared -fPIC -o libD.so d.c
}

cleanall() {
	rm *.so
	rm ldout
	rm rdout1
	rm rdout2
}



cleanall
#build shared libraries
dependencySharedlib
sharedlib

#load-time dynamic linking executable
gcc -o ldout main.c libmodA.so libmodB.so -Xlinker -rpath ./

#run-time dynamic linking executable with dependency modules
gcc -rdynamic -o rdout1 main2.c -ldl

#run-time dynamic linking executable without dependency modules
gcc -rdynamic -o rdout2 main3.c -ldl

