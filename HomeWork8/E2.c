/*
    Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
*/
#include <stdio.h>
#include <limits.h>

#define ARRAY_LNG   5

//Переменные
int nums[ARRAY_LNG];

int main(void){
    int min = INT_MAX;
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
        if(nums[i] < min){
            min = nums[i];
        }
    }
    printf("%d", min);
    return 0;
}