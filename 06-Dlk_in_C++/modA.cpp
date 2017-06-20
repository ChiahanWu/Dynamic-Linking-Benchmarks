#include <iostream>
#include "modA.hpp"
#include "modB.hpp"

void modA::init() {
	// Call a function defined in module B
    modB* b = create_modB_instance();
    b->funcModB();
}

void modA::funcModA() {
    std::cout << "function in module A called" << std::endl;
}

modA* create_modA_instance() {
    return new modA;
}


/* class factory functions */
extern "C" module* create() {
    return new modA;
}

extern "C" void destroy(module* p) {
    delete p;
}


