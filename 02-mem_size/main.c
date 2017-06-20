#include "vector.h"

#define arrsize 20000

int main() {
    int x[arrsize] ,y[arrsize], z[arrsize];
    int l,i;

   
    // initilaize array
    for (i = 0; i < arrsize; i++) {
    	x[i] = i;
    	y[i] = -i;
    }

    while(1) {
        addvec(x, y, z);
        multvec(x, y, z);
    }

    return 0;
}


