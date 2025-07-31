/*
    Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
*/
#include <stdio.h>
#include <limits.h>

#define ARRAY_LNG   10

//Переменные
int nums[ARRAY_LNG];

int main(void){
    int sum = 0;

    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
        if(nums[i] > 0){
           sum += nums[i];
        }
    }
    printf("%d", sum);
    return 0;
}