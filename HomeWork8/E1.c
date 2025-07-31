/*
    Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.
*/
#include <stdio.h>

#define ARRAY_LNG   5

//Переменные
float nums[ARRAY_LNG];

int main(void){
    float sum = 0;
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%f", (nums + i));
        sum += nums[i];
    }
    sum /= ARRAY_LNG;
    printf("%.3f", sum);
    return 0;
}