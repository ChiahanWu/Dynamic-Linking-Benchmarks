#!/bin/sh

gcc -shared -fPIC -o libint.so addint.c 
gcc -shared -fPIC -o libdbl.so adddbl.c
gcc -shared -fPIC -o libstr.so addstr.c

gcc -rdynamic -o dlrun main.c -ldl
