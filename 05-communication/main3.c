#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    void (*callA)();
    void (*callB)();


    /* open the library */
	printf("Opening Module A...\n");
    void* handleA = dlopen("./libA.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handleA) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
    }


    printf("Opening Module B...\n");
    void* handleB = dlopen("./libB.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handleB) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    printf("Opening Module C...\n");
    void* handleC = dlopen("./libC.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handleC) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    printf("Opening Module D...\n");
    void* handleD = dlopen("./libD.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handleD) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    callA = dlsym(handleA, "a");
	callA();

	callB = dlsym(handleB, "b");
	callB();

    return 0;
}
