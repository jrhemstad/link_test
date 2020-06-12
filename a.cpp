#include "singleton.hpp"

namespace A{

void set(int v){
    instance() = v;
}

int get(){
    return instance();
}

}
