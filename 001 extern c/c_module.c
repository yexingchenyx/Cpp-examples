#include "c_module.h"

#include <printf.h>

int c_add(int a, int b) {
    printf("call c_add\n");
    return a + b;
}