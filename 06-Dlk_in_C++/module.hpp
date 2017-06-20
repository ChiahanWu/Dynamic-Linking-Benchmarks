#ifndef FWK_INCLUDE_MODULE_HPP_
#define FWK_INCLUDE_MODULE_HPP_

class module {
public:
    virtual void init() = 0;
};

typedef module* create_t();
typedef void destroy_t(module*);

#endif



