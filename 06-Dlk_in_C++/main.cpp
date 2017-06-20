#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "module.hpp"

int main(int argc, char *argv[]) {
    /* open shared libraries */
    std::cout << "Opening ModA.so...\n";
    void* handleA = dlopen("./libmodA.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handleA) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    std::cout << "Opening ModB.so...\n";
    void* handleB = dlopen("./libmodB.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handleB) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    /* load the class factory symbols */
    std::cout << "Loading class factory symbols...\n";

    create_t* create_modA =
               reinterpret_cast<create_t*> (dlsym(handleA, "create"));
    destroy_t* destroy_modA =
               reinterpret_cast<destroy_t*> (dlsym(handleA, "destroy"));

    create_t* create_modB =
               reinterpret_cast<create_t*> (dlsym(handleB, "create"));
    destroy_t* destroy_modB =
               reinterpret_cast<destroy_t*> (dlsym(handleB, "destroy"));

    /* create an instance for each class */
    std::cout << "Creating module A...\n";
    module* modA = create_modA();

    std::cout << "Creating module B...\n";
    module* modB = create_modB();

    /* initialize all modules */
    modA->init();

    modB->init();

    /* destroy each modules' instance */
    std::cout << "Destroying module A...\n";
    destroy_modA(modA);

    std::cout << "Destroying module B...\n";
    destroy_modB(modB);

    /* close shared libraries */
    std::cout << "Closing module A...\n";
    dlclose(handleA);

    std::cout << "Closing module B...\n";
    dlclose(handleB);

    return 0;
}