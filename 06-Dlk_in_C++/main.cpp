#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "module.hpp"

int main(int argc, char *argv[]) {
    /* open the library */
    std::cout << "Opening ModA.so...\n";
    void* handleNas = dlopen("./libmodA.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handleNas) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    std::cout << "Opening ModB.so...\n";
    void* handleS1ap = dlopen("./libmodB.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handleS1ap) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    /* load the class factory symbols */
    std::cout << "Loading class factory symbols...\n";

    create_t* create_nas =
               reinterpret_cast<create_t*> (dlsym(handleNas, "create"));
    destroy_t* destroy_nas =
               reinterpret_cast<destroy_t*> (dlsym(handleNas, "destroy"));

    create_t* create_s1ap =
               reinterpret_cast<create_t*> (dlsym(handleS1ap, "create"));
    destroy_t* destroy_s1ap =
               reinterpret_cast<destroy_t*> (dlsym(handleS1ap, "destroy"));

    /* create an instance of the class */
    std::cout << "Creating nas module...\n";
    module* nas = create_nas();

    std::cout << "Creating s1ap module...\n";
    module* s1ap = create_s1ap();

    /* initialize all modules */
    nas->init();

    s1ap->init();

    /* destroy each modules' instance */
    std::cout << "Destroying nas module...\n";
    destroy_nas(nas);

    std::cout << "Destroying s1ap module...\n";
    destroy_s1ap(s1ap);

    /* close shared libraries */
    std::cout << "Closing library...\n";
    dlclose(handleNas);

    std::cout << "Closing library...\n";
    dlclose(handleS1ap);

    return 0;
}