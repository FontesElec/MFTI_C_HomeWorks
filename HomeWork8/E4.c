/*
    Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
*/
#include <stdio.h>
#include <limits.h>

#define ARRAY_LNG   10

//Переменные
int nums[ARRAY_LNG];

int main(void){
    int f_max = INT_MIN;
    int s_max = INT_MIN;

    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
        if(nums[i] > f_max){
            s_max = f_max;
            f_max = nums[i];
        }
        else if(nums[i] > s_max){
            s_max = nums[i];
        }
    }
    printf("%d", s_max + f_max);
    return 0;
}