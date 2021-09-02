#include "cpp_module.h"
#include <iostream>

int cpp_add(int a, int b) {
    std::cout << "call cpp_add" << std::endl;
    return a + b;
}