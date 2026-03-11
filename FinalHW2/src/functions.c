#include "functions.h"

float linear(float x){
    return 0.6 * x + 3;
}

float deriv_linear(float x){
    (void)x;
    return 0.6;
}

float powered(float x){
    return (x - 2) * (x - 2) * (x - 2) - 1;
}

float deriv_powered(float x){
    return 3 * (x - 2) * (x - 2);
}

float hyperbolic(float x){
    return 3 / x;
}

float deriv_hyperbolic(float x){
    return -3 / (x * x);
}
