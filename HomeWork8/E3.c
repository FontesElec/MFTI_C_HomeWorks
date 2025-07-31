/*
    Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
*/
#include <stdio.h>
#include <limits.h>

#define ARRAY_LNG   10

//Переменные
int nums[ARRAY_LNG];

int main(void){
    int min = INT_MAX;
    int max = INT_MIN;
    int num_min = 0;
    int num_max = 0;
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
        if(nums[i] < min){
            min = nums[i];
            num_min = i + 1;
        }
        if(nums[i] > max){
            max = nums[i];
            num_max = i + 1;
        }
    }
    printf("%d %d %d %d", num_max, max, num_min, min);
    return 0;
}