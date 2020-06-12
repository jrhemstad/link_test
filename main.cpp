#include "a.hpp"
#include "b.hpp"
#include <iostream>

int main(void){
    A::set(42);
    std::cout << B::get() << std::endl;
}