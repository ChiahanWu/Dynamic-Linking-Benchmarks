#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    void (*callA)();
    void (*callB)();


    /* open the library */
	printf("Opening Module A...\n");
    void* handleA = dlopen("./libmodA.so", RTLD_LAZY);
    if (!handleA) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
    }

    printf("Opening Module B...\n");
    void* handleB = dlopen("./libmodB.so", RTLD_LAZY);
    if (!handleB) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }


    callA = dlsym(handleA, "a");
	callA();

	callB = dlsym(handleB, "b");
	callB();

    return 0;
}
