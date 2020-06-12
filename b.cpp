#include "singleton.hpp"

namespace B{

void set(int v){
    instance() = v;
}

int get(){
    return instance();
}

}