#include <iostream>
#include "modB.hpp"
#include "modA.hpp"

void modB::init() {
	// Call a function defined in module B
    modA* a = create_modA_instance();
    a->funcModA();
}

void modB::funcModB() {
    std::cout << "function in module B called" << std::endl;
}

modB* create_modB_instance() {
    return new modB;
}

/* class factory functions */
extern "C" module* create() {
    return new modB;
}

extern "C" void destroy(module* p) {
    delete p;
}



