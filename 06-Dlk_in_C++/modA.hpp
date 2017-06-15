#include "module.hpp"

class nas : public module {
 public:

    virtual void init();
    void funcNas_A();
    void funcNas_B();

};
nas* create_n();