#include "vector.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#define arrsize 50

int main() {
    void *handle;
    void (*addvec)(int *, int *, int *);
    void (*multvec)(int *, int *, int *);
    char *error;

    int x[arrsize] ,y[arrsize], z[arrsize];
    int i;
    clock_t start_t, end_t;


    // initilaize array
    for (i = 0; i < arrsize; i++) {
        x[i] = i;
        y[i] = -i;
    }

    // load the shared library
    handle = dlopen("./libvector.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    /// get pointer to the addvec()
    addvec = dlsym(handle, "addvec");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    /// get pointer to the multvec()
    multvec = dlsym(handle, "multvec");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    start_t = clock();
    for (i = 0; i < 10000000; i++) {
        addvec(x, y, z);
        multvec(x, y, z);
    }
    end_t = clock();

    printf("%f", (double) (end_t - start_t));

    // Unload the shared library
    if (dlclose(handle) < 0) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    return 0;
}




