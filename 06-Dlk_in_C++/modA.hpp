#include "module.hpp"

class modA : public module {
 public:

    virtual void init();
    void funcModA();
};

modA* create_modA_instance();