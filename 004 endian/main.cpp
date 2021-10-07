#include <iostream>
#include <boost/endian.hpp>
#include <inttypes.h>

int main(int argc, char** argv) {

    /**
     * 判断当前cpu是采用big endian还是little endian
     * 兼容intel cpu一般为 litte
     * 网络传输用 big
     */
    bool is_little;
    {
        int n = 1;
        if(*(char *)&n == 1) {
            is_little = true;
            printf("little endian\n");
        } else {
            is_little = false;
            printf("big endian\n");
        }
    }

    int8_t i8 = 123;
    int16_t i16 = 123;
    int32_t i32 = 123;
    int64_t i64 = 123;
    float f32 = 123.0;
    double f64 = 123.0;

    boost::endian::endian_reverse_inplace(i8);
    boost::endian::endian_reverse_inplace(i16);
    boost::endian::endian_reverse_inplace(i32);
    boost::endian::endian_reverse_inplace(i64);
    boost::endian::endian_reverse_inplace(f32);
    boost::endian::endian_reverse_inplace(f64);

    printf("inverse:\n");
    printf("i8: %d\n", i8);
    printf("i16: %d\n", i16);
    printf("i32: %d\n", i32);
    printf("i64: %llu\n", i64);
    printf("f32: %f\n", f32);
    printf("f64: %f\n", f64);

    if (is_little) {
        boost::endian::big_to_native_inplace(i8);
        boost::endian::big_to_native_inplace(i16);
        boost::endian::big_to_native_inplace(i32);
        boost::endian::big_to_native_inplace(i64);
        boost::endian::big_to_native_inplace(f32);
        boost::endian::big_to_native_inplace(f64);
    } else {
        boost::endian::little_to_native_inplace(i8);
        boost::endian::little_to_native_inplace(i16);
        boost::endian::little_to_native_inplace(i32);
        boost::endian::little_to_native_inplace(i64);
        boost::endian::little_to_native_inplace(f32);
        boost::endian::little_to_native_inplace(f64);
    }

    printf("to native:\n");
    printf("i8: %d\n", i8);
    printf("i16: %d\n", i16);
    printf("i32: %d\n", i32);
    printf("i64: %llu\n", i64);
    printf("f32: %f\n", f32);
    printf("f64: %f\n", f64);

}