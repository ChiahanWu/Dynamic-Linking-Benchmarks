#include <stdio.h>

void funcModA();

void funcModB() {
    printf("Module B function called\n");
}


void callModA() {
	printf("in callModA\n");

	funcModA();     
}

