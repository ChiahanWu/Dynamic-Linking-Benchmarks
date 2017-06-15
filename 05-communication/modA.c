#include <stdio.h>

void funcModB();

void funcModA() {
    printf("Module A function called\n");
}


void callModB() {
	printf("in callModB\n");

	funcModB();     
}

