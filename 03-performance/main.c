#include <time.h>
#include <stdio.h>
#include "vector.h"

#define arrsize 5

int main() {
    int x[arrsize] ,y[arrsize], z[arrsize];
    int l,i;
    clock_t start_t, end_t;
   
    // initilaize array
    for (i = 0; i < arrsize; i++) {
    	x[i] = i;
    	y[i] = -i;
    }

    start_t = clock();

    for (i = 0; i < 100000; i++) {
        addvec(x, y, z);
        multvec(x, y, z);
    }
    end_t = clock();

    printf("%f", (double) (end_t - start_t));

    return 0;
}


