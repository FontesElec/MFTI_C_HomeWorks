#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef float(*func)(float);
struct flags{
    uint8_t absc  :1;
    uint8_t iters :1;
    uint8_t square:1;
};

struct flags config = {0, 0, 0};


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
    if(config.iters){
        printf("Find Tangent Search root for %d steps ", cntr);
    }
    return x1;
}

float integral(func f, float a, float b, float eps2){
    float sum = 0;
    float step = (b - a) / eps2;
    for(float x = a + eps2; x < b - eps2; x += eps2){
        sum += 0.5 * eps2 * (f(x) + f(x + eps2));
    }
    return sum;
}

void test_program(void){

    float x1 = 0, x2 = 0, x3 = 0;
    x1 = root(hyperbolic, linear, deriv_hyperbolic, deriv_linear, 0.2, 10, 0.0001);
    x2 = root(hyperbolic, powered, deriv_hyperbolic, deriv_powered, 0.2, 10, 0.0001);
    x3 = root(linear, powered, deriv_linear, deriv_powered, 0.2, 10, 0.0001);

    if(config.absc){
        printf("root of crossing linear and hyperbolic function\n in diapason [0.2, 10]: %f \n", x1);
        printf("root of crossing powered and hyperbolic function\n in diapason  [0.2, 10]: %f \n", x2);
        printf("root of crossing linear and powered function\n in diapason  [0.2, 10]: %f \n", x3);
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
        printf("integral of linear function in diapason [%.3lf, %.3lf] is equal %f", x1, x3, S1);
        printf("integral of hyperbolic function in diapason [%.3lf, %.3lf] is equal %f", x1, x2, S2);
        printf("integral of powered function in diapason [%.3lf, %.3lf] is equal %f", x2, x3, S3);
    }

    printf("Current square of figure is %f \n", (S1 - S2 - S3));
}

void print_help(void){
    printf("Flags:\n");
    printf("-h or -help will return list off available commands\n");
    printf("-a will return abscisses of crossing functions\n");
    printf("-i will return cuantity of operations by finding rootes\n");
    printf("-s will return result of square calculation\n");
    printf("-tr(a b) will return founded root between a and b\n");
    printf("-ti(a b) will return result of operation by finding scuare of figure between a and b\n");
    printf("if no flags sent, program execute test function without additional information\n");
}

void test_roots(int i, char** c){
    char* endptr = NULL;
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
    x1 = root(hyperbolic, linear, deriv_hyperbolic, deriv_linear, a, b, 0.0001);
    printf("root of crossing linear and hyperbolic function in diapason [%.3lf, %.3lf]: %f \n", a, b, x1);
    
    x2 = root(hyperbolic, powered, deriv_hyperbolic, deriv_powered, a, b, 0.0001);
    printf("root of crossing powered and hyperbolic function in diapason [%.3lf, %.3lf]: %f \n", a, b, x2);

    x3 = root(linear, powered, deriv_linear, deriv_powered, a, b, 0.0001);
    printf("root of crossing linear and powered function in diapason [%.3lf, %.3lf]: %f \n", a, b, x3);
}

void test_integral(int i, char** c){
    char* endptr = NULL;
    double a = strtod(*(c + i + 1), &endptr);
    if(*endptr != '\0'){
        printf("wrong command parameter, integral test failed2\n");
        return;
    }
    endptr = NULL;
    double b = strtod(*(c + i + 2), &endptr);
    if(*endptr != '\0'){
        printf("wrong command parameter, integral test failed3\n");
        return;
    }

    float S1 = integral(linear, a, b, 0.0001);
    printf("integral of linear function in diapason [%.3lf, %.3lf] is equal %f", a, b, S1);

    float S2 = integral(hyperbolic, a, b, 0.0001);
    printf("integral of hyperbolic function in diapason [%.3lf, %.3lf] is equal %f", a, b, S2);

    float S3 = integral(powered, a, b, 0.0001);
    printf("integral of powered function in diapason [%.3lf, %.3lf] is equal %f", a, b, S3);
}
 

void parse_command(char** com, int i){
    if(!strcmp("-h", com[i])){
        printf("called help\n");
        print_help();
    }
    else if(!strcmp("-help", com[i])){
        printf("called help\n");
        print_help();
    }
    else if(!strcmp("-a", com[i])){
        config.absc = 1;
        printf("called absc\n");
    }
    else if(!strcmp("-i", com[i])){
        config.iters = 1;
        printf("called iters\n");
    }
    else if(!strcmp("-s", com[i])){
        config.square = 1;
        printf("called square\n");
    }
    else if(!strcmp("-tr", com[i])){
        printf("called test roots\n");
        test_roots(i, com);
    }
    else if(!strcmp("-ti", com[i])){
        printf("called test integral\n");
        test_integral(i, com);
    }
}


int main(int argc, char* argv[]){
    if(argc == 1){
        test_program();
        return 0;
    }
    else{
        for(int i = 1; i < argc; i++){
            if(*(argv[i]) == '-'){
                parse_command(argv, i);
            }
            else{
                i++;
            }
        }
    }
    if(config.absc || config.iters || config.square){
        test_program();
    }
    return 0;
}