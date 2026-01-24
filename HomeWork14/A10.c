/*
        Необходимо реализовать программу, которой на входе передаётся вещественное число в типе float, 
        она возвращает порядок который хранится в поле EXP в виде десятичного целого числа. 
        Функция должна строго соответствовать прототипу
        int extractExp(float)
*/


#include <stdio.h>
#include <stdint.h>

int extractExp(float num){
    int res = 0;
    res = ((*((uint32_t*)(&num))) >> 23) & 0xff;
    return res;
}

int main(void){
    float input;
    scanf("%f", &input);
    printf("%d", extractExp(input));
    return 0;
}
