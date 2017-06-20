#include "module.hpp"

class modB : public module {
 public:

    virtual void init();
    void funcModB();
};

modB* create_modB_instance();