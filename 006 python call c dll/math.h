#ifndef __MATH_H__
#define __MATH_H__

void print_hello_world();

void print_format(const char* format, ...);

int add(int a, int b);

void add_arr(int* a, int* b, int* c, int n);

typedef struct
{
    int x;
    int y;
} Point;

void add_point(Point* a, Point* b, Point* c);


#endif