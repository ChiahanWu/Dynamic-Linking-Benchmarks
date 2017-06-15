#include <pthread.h>
#include <iostream>
#include "modB.hpp"
#include "modA.hpp"


void* callNas(void *) {
    std::cout << "in callNas:" << std::endl;
    
    nas *n = create_n();
   
    n->funcNas_A();
    n->funcNas_B();

}

void s1ap::init() {
    std::cout << "creating s1ap module thread..." << std::endl;
    // itti_create_task (TASK_NAS_MME, &nas_intertask_interface, NULL)
    pthread_t tid;
    pthread_create(&tid, NULL, callNas, NULL);
    pthread_join(tid, NULL);
}


void s1ap::funcS1ap_A() {
    std::cout << "s1ap module function A called" << std::endl;
}

void s1ap::funcS1ap_B() {
    std::cout << "s1ap module function B called" << std::endl;
}


/* class factories */
s1ap* create_s() {
    return new s1ap;
}
extern "C" module* create() {
    return new s1ap;
}

extern "C" void destroy(module* p) {
    delete p;
}


