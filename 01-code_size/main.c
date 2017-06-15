#include "vector.h"

#define arrsize 50

int main() {
    int x[arrsize] ,y[arrsize], z[arrsize];
    int i;

    // initilaize array
    for (i = 0; i < arrsize; i++) {
    	x[i] = i;
    	y[i] = -i;
    }

    addvec(x, y, z);
    multvec(x, y, z);

    return 0;
}


