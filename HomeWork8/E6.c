/*
    Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.
*/
#include <stdio.h>

#define ARRAY_LNG   12

//Переменные
float nums[ARRAY_LNG];

int main(void){
    float sum = 0;
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%f", (nums + i));
        sum += nums[i];
    }
    sum /= ARRAY_LNG;
    printf("%.2f", sum);
    return 0;
}