#include <pthread.h>
#include <iostream>
#include "modA.hpp"
#include "modB.hpp"


void* callS1ap(void* arg) {
    std::cout << "in callS1ap:" << std::endl;
    
    s1ap* s = create_s();
	

    s->funcS1ap_A();
    s->funcS1ap_B();
   
    return NULL;
}



void nas::init() {
    std::cout << "creating nas module thread..." << std::endl;
    // itti_create_task (TASK_NAS_MME, &nas_intertask_interface, NULL)
    pthread_t tid;
    pthread_create(&tid, NULL, callS1ap, NULL);
    pthread_join(tid, NULL);
}


void nas::funcNas_A() {
    std::cout << "nas module function A called" << std::endl;
}

void nas::funcNas_B() {
    std::cout << "nas module function B called" << std::endl;
}



/* the class factories */
nas* create_n() {
    return new nas;
}
extern "C" module* create() {
    return new nas;
}

extern "C" void destroy(module* p) {
    delete p;
}


