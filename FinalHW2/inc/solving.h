#include <stdint.h>

typedef float(*func)(float);
struct flags{
    uint8_t absc  :1;
    uint8_t iters :1;
    uint8_t square:1;
};

void test_program(void);
void test_roots(int i, char** c);
void test_integral(int i, char** c);
float root(func f, func g, func df, func dg, float a, float b, float eps1);
float integral(func f, float a, float b, float eps2);
