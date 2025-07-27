/*
    Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
*/
#include <stdio.h>

#define SOLVING_DEPTH   5                              //сколько слагаемых будем использовать для вычисления синуса 
#define M_PI            3.14159265358979323846         //уже с этого момента было бы проще использовать math.h

//Прототипы функций
float sinus(float x);
int factorial(int x);
float power(float num, int pow);
float to_rad(float deg);

//Переменные
float num;

int main(void){
    scanf("%f", &num);
    printf("%.3f", sinus(to_rad(num)));
    return 0;
}


float sinus(float x){
    float res = 0;
    int sign = 1;
    for(int i = 0; i < SOLVING_DEPTH; i++){
        res += sign *  power(x, 2 * i + 1) / (float)factorial(2 * i + 1);
        sign *= -1;
    }
    return res;
}

int factorial(int x){
    int res = 1;
    for(int i = 1; i <= x; i++){
        res *= i;
    }
    return res;
}

float power(float num, int pow){
    float res = 1.0;
    for(int i = 0; i < pow; i++){
        res *= num;
    }
    return res;
}

float to_rad(float deg){
    return deg * M_PI / 180.0;
}