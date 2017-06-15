#include "module.hpp"


class s1ap : public module {
 public:

    virtual void init();
    void funcS1ap_A();
    void funcS1ap_B();
};
s1ap* create_s() ;