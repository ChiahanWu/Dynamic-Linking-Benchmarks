#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#define arrsize 5

int main(int argc, char *argv[]) {
    void *handle;
    char *error;
    void *func;

    // load the shared library
    handle = dlopen(argv[1], RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    /// get function symbol
    func = dlsym(handle, argv[2]);
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    switch(argv[2][3]) {
        case 'i':
        {
            int (*addint)(int, int) = func;
            int x = atoi(argv[3]);
            int y = atoi(argv[4]);
            int z = addint(x,y);
            printf("result = %d\n",z);
            break;
        }
        case 'd':
        {
            double (*adddbl)(double, double) = func;
            double x = atof(argv[3]);
            double y = atof(argv[4]);
            double z = adddbl(x,y);
            printf("result = %f\n",z);
            break;
        }
        case 's':
        {
            char* (*addstr)(char *, char *) = func;
            char *s = addstr(argv[3],argv[4]);
            printf("result = %s\n",s);
            break;
        }

    } 

    // Unload the shared library
    if (dlclose(handle) < 0) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    return 0;
}




