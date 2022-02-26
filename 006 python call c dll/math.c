#include "math.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void print_hello_world() {
    printf("hello world\n");
}

void print_format(const char* format, ...) {
    va_list ap;

    int size = 100;
    char* buffer = (char*)malloc(size);

    va_start(ap, format);
    vsprintf(buffer, format, ap);
    va_end(ap);

    printf("%s", buffer);
    free(buffer);
}

int add(int a, int b) {
    return a + b;
}

void add_arr(int* a, int* b, int* c, int n) {
    for (int i = 0; i < n; ++i)
        c[i] = a[i] + b[i];
}

void add_point(Point* a, Point* b, Point* c) {
    c->x = a->x + b->x;
    c->y = a->y + b->y;
}
