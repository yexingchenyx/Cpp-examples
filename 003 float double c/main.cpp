#include <iostream>
#include "my_statistics_float.h"
#include "my_statistics_double.h"

int main(int argc, char** argv) {
    float a[5] = {1, 2, 3, 4, 5};
    double b[5] = {10, 20, 30, 40, 50};

    std::cout << my_stats_float_max(a, 5) << std::endl;
    std::cout << my_stats_double_max(b, 5) << std::endl;
}