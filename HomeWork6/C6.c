/*
   Необходимо составить функцию, которая определяет, сколько зерен попросил положить на N-ую клетку изобретатель шахмат 
   (на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)
*/
#include <stdio.h>

//Прототипы функций
unsigned long get_pow_of_two(int pow);    //вся логика подчиняется простому суммированию степеней двойки, поэтому создадим отдельно функцию возведения в степень
unsigned long get_grain_qty(int step);

int main(void){
    int num;
    scanf("%d", &num);
    printf("%lu", get_grain_qty(num));
    return 0;
}

unsigned long get_pow_of_two(int pow){
    unsigned long ret = 1;
    for(int i = 1; i < pow; i++){
        ret *= 2;
    }
    return ret;
}

unsigned long get_grain_qty(int step){
    return get_pow_of_two(step);
}