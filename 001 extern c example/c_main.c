#include "c_module.h"
#include "cpp_module.h"

int main(int argc, char** argv) {
    int c = c_add(1, 2);
    int d = cpp_add(1, 2);
    return 0;
}