#include <math.h>
#include <stdio.h>


typedef float(*func)(float);


float linear(float x){
    return 0.6 * x + 3;
}

float deriv_linear(float x){
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

float root(func f, func g, func df, func dg, float a, float b, float eps1){
    /*
        Поиск корней сведём к вычитанию первой функции из второй с поиском пересечения с нулём
        Учитываем что производная разности функций равна равности их производных
    */

    //Для определения, с какой стороны от предела начинать поиск, определимся со знаком производной
    float dfg = dg(a) - df(a);

    float x = 0, end_x = 0;
    int cntr = 0;
    
    if(dfg < 0){
        x = a;
        end_x = b;
    }
    else{
        x = b;
        end_x = a;
    }

    float x1 = x - (g(x) - f(x)) / (dg(x) - df(x));
    float x0 = x;

    while((fabs(x0 - x1) > eps1) && (x >= a) && (x <= b)){
        x0 = x1;
        x1 = x1 - (g(x1) - f(x1)) / (dg(x1) - df(x1));
        cntr++;
    }
    printf("Find Tangent Search root for %d steps ", cntr);
    return x1;
}


int main(void){
    float x = 0;
    x = root(hyperbolic, linear, deriv_hyperbolic, deriv_linear, 0.2, 10, 0.0001);
    printf("1st func root: %f \n", x);
    
    x = root(hyperbolic, powered, deriv_hyperbolic, deriv_powered, 0.2, 10, 0.0001);
    printf("2nd func root: %f \n", x);

    x = root(linear, powered, deriv_linear, deriv_powered, 0.2, 10, 0.0001);
    printf("3rd func root: %f \n", x);
    
}