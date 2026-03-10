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

    float x = a;
    float end_x = b;
    int cntr = 0;

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

float integral(func f, float a, float b, float eps2){
    float sum = 0;
    float step = (b - a) / eps2;
    for(float x = a + eps2; x < b - eps2; x += eps2){
        sum += 0.5 * eps2 * (f(x) + f(x + eps2));
    }
    printf("calculated square: %f \n", sum);
    return sum;
}


int main(void){
    float x1 = 0, x2 = 0, x3 = 0;
    x1 = root(hyperbolic, linear, deriv_hyperbolic, deriv_linear, 0.2, 10, 0.0001);
    printf("1st func root: %f \n", x1);
    
    x2 = root(hyperbolic, powered, deriv_hyperbolic, deriv_powered, 0.2, 10, 0.0001);
    printf("2nd func root: %f \n", x2);

    x3 = root(linear, powered, deriv_linear, deriv_powered, 0.2, 10, 0.0001);
    printf("3rd func root: %f \n", x3);
    
    /*
        Ограничение сверху фигуры происходит за счёт лиейной функции, соответственно, 
        её площадь является базовой, из неё вычтем площади фигур,
        ограниченных гиперболой и степенной функцией
    */
    float S1 = integral(linear, x1, x3, 0.0001);
    float S2 = integral(hyperbolic, x1, x2, 0.0001);
    float S3 = integral(powered, x2, x3, 0.0001);

    printf("Current square of figure is %f \n", (S1 - S2 - S3));

}