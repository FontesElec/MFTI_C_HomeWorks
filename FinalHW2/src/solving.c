#include "solving.h"
#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct flags config = {0, 0, 0};

void test_program(void){

    printf("\n-------------------Test function---------------------\n");

    float x1 = 0, x2 = 0, x3 = 0;
    x1 = root(hyperbolic, linear, deriv_hyperbolic, deriv_linear, 0.2, 10, 0.0001);
    x2 = root(hyperbolic, powered, deriv_hyperbolic, deriv_powered, 0.2, 10, 0.0001);
    x3 = root(linear, powered, deriv_linear, deriv_powered, 0.2, 10, 0.0001);

    if(config.absc){
        printf("root of crossing linear and hyperbolic function in diapason [0.2, 10]: %f \n", x1);
        printf("root of crossing powered and hyperbolic function in diapason  [0.2, 10]: %f \n", x2);
        printf("root of crossing linear and powered function in diapason  [0.2, 10]: %f \n", x3);
    }   
    
    /*
        Ограничение сверху фигуры происходит за счёт линейной функции, соответственно, 
        её площадь является базовой, из неё вычтем площади фигур,
        ограниченных гиперболой и степенной функцией
    */
    float S1 = integral(linear, x1, x3, 0.0001);
    float S2 = integral(hyperbolic, x1, x2, 0.0001);
    float S3 = integral(powered, x2, x3, 0.0001);

    if(config.square){
        printf("integral of linear function in diapason [%.3lf, %.3lf] is equal %f \n", x1, x3, S1);
        printf("integral of hyperbolic function in diapason [%.3lf, %.3lf] is equal %f\n", x1, x2, S2);
        printf("integral of powered function in diapason [%.3lf, %.3lf] is equal %f\n", x2, x3, S3);
    }

    printf("Current square of figure is %f \n", (S1 - S2 - S3));

    printf("\n-----------------------------------------------------");
}

void test_roots(int i, char** c){

    printf("\n---------------------Roots test----------------------\n");
    char* endptr = NULL;
    uint8_t set_flg = 0;
    double a = strtod(*(c + i + 1), &endptr);
    if(*endptr != '\0'){
        printf("wrong command parameter, root test failed\n");
        return;
    }
    endptr = NULL;
    double b = strtod(*(c + i + 2), &endptr);
    if(*endptr != '\0'){
        printf("wrong command parameter, root test failed\n");
        return;
    }
    float x1 = 0, x2 = 0, x3 = 0;
    if(config.absc == 1){
        config.absc = 0;
        set_flg = 1;
    }
    x1 = root(hyperbolic, linear, deriv_hyperbolic, deriv_linear, a, b, 0.0001);
    printf("root of crossing linear and hyperbolic function in diapason [%.3lf, %.3lf]: %f \n", a, b, x1);
    
    x2 = root(hyperbolic, powered, deriv_hyperbolic, deriv_powered, a, b, 0.0001);
    printf("root of crossing powered and hyperbolic function in diapason [%.3lf, %.3lf]: %f \n", a, b, x2);

    x3 = root(linear, powered, deriv_linear, deriv_powered, a, b, 0.0001);
    printf("root of crossing linear and powered function in diapason [%.3lf, %.3lf]: %f \n", a, b, x3);
    if(set_flg){
        config.absc = 1;
    }
    printf("\n-----------------------------------------------------\n");
}

void test_integral(int i, char** c){

    printf("\n--------------------Integral test-------------------\n");
    char* endptr = NULL;
    double a = strtod(*(c + i + 1), &endptr);
    if(*endptr != '\0'){
        printf("wrong command parameter, integral test failed\n");
        return;
    }
    endptr = NULL;
    double b = strtod(*(c + i + 2), &endptr);
    if(*endptr != '\0'){
        printf("wrong command parameter, integral test failed\n");
        return;
    }

    uint8_t set_flg = 0;
    if(config.square == 1){
        config.square = 0;
        set_flg = 1;
    }

    float S1 = integral(linear, a, b, 0.0001);
    printf("integral of linear function in diapason [%.3lf, %.3lf] is equal %f \n", a, b, S1);

    float S2 = integral(hyperbolic, a, b, 0.0001);
    printf("integral of hyperbolic function in diapason [%.3lf, %.3lf] is equal %f \n", a, b, S2);

    float S3 = integral(powered, a, b, 0.0001);
    printf("integral of powered function in diapason [%.3lf, %.3lf] is equal %f \n", a, b, S3);

    if(set_flg){
        config.square = 1;
    }

    printf("\n-----------------------------------------------------\n");
}
 

float root(func f, func g, func df, func dg, float a, float b, float eps1){
    /*
        Поиск корней сведём к вычитанию первой функции из второй с поиском пересечения с нулём
        Учитываем что производная разности функций равна равности их производных
    */

    float x = a;
    int cntr = 0;

    float x1 = x - (g(x) - f(x)) / (dg(x) - df(x));
    float x0 = x;

    while((fabs(x0 - x1) > eps1) && (x1 >= a) && (x1 <= b)){
        x0 = x1;
        x1 = x1 - (g(x1) - f(x1)) / (dg(x1) - df(x1));
        cntr++;
    }
    
    if(config.iters){
        if(fabs(x0 - x1) > eps1){
            printf("No roots found\n");
            return 0;
        }
        else{
            printf("Find tangent search root for %d steps\n", cntr);   
        }
    }
    return x1;
}

float integral(func f, float a, float b, float eps2){
    float sum = 0;
    for(float x = a + eps2; x < b - eps2; x += eps2){
        sum += 0.5 * eps2 * (f(x) + f(x + eps2));
    }
    return sum;
}
