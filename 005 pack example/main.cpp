#include <iostream>

/**
 * 结构体内每个变量的对其系数为其自身的对齐系数与pack指定的对齐系数的小的那一个
 * 结构体的整体对齐系数为其所有变量的对齐系数与alignas指定的对齐系数的大的那一个
 * 
 */

#pragma pack(1)
typedef struct {
    char a; // 1 bytes
    double b; // 8 bytes
    int c; // 4 bytes
} A1;
#pragma pack()

typedef struct {
    char a; // 1 bytes
    double b; // 8 bytes
    int c; // 4 bytes
} A2;

#pragma pack(4)
typedef struct {
    char a; // 1 bytes
    double b; // 8 bytes
    int c; // 4 bytes
} A3;
#pragma pack()

#pragma pack(4)
typedef struct alignas(8) {
    char a; // 1 bytes 对齐到 min(alignof(char), pack) = min(1, 4) = 1  内存位置 [0, 1)
    double b; // 8 bytes 对齐到 min(alignof(double), pack) = min(8, 4) = 4 内存位置 [4, 12)
    int c; // 4 bytes 对齐到 min(alignof(int), pack) = min(4, 4) = 4 内存位置 [12, 16)
} A4; // 16 bytes 对齐到 max(a, b, c, alignas) = max(1, 4, 4, 8) = 8 内存位置 [0, 16)
#pragma pack()


int main(int argc, char** argv) {
    printf("alignof char=%lu, double=%lu, int=%lu\n", alignof(char), alignof(double), alignof(int));
    printf("A1 sizeof=%lu, alignof=%lu\n", sizeof(A1), alignof(A1));
    printf("A2 sizeof=%lu, alignof=%lu\n", sizeof(A2), alignof(A2));
    printf("A3 sizeof=%lu, alignof=%lu\n", sizeof(A3), alignof(A3));
    printf("A4 sizeof=%lu, alignof=%lu\n", sizeof(A4), alignof(A4));
}