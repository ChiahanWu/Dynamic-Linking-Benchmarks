#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    void (*callModB)();
    void (*callModA)();


    /* open the library */
	printf("Opening ModA.so...\n");
    void* handleA = dlopen("./libmodA.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handleA) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
    }


    printf("Opening ModB.so...\n");
    void* handleB = dlopen("./libmodB.so", RTLD_LAZY | RTLD_GLOBAL);
	if (!handleB) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
    }

    callModB = dlsym(handleA, "callModB");
	callModB();

	callModA = dlsym(handleB, "callModA");
	callModA();

    return 0;
}
