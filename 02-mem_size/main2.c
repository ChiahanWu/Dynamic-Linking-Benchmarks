#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#define arrsize 20000

int main() {
    void *handle;
    void (*addvec)(int *, int *, int *);
    void (*multvec)(int *, int *, int *);
    char *error;

    int x[arrsize] ,y[arrsize], z[arrsize];
    int i;

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

    while(1) {
        addvec(x, y, z);
        multvec(x, y, z);
    }
    

    // Unload the shared library
    if (dlclose(handle) < 0) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    return 0;
}




