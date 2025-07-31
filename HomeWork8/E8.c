/*
    Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
*/
#include <stdio.h>

#define ARRAY_LNG   12

//Переменные
int nums[ARRAY_LNG];

int main(void){
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
    }

    for(int i = 0; i < ARRAY_LNG; i++){
        if(i < 2){
            int tmp = nums[i];
            nums[i] = nums[3 - i];
            nums[3 - i] = tmp;
        }
        if((i > 3) && (i < 6)){
            int tmp = nums[i];
            nums [i] = nums[11 - i];
            nums[11 - i] = tmp;
        }
        if((i > 7) & (i < 10)){
            int tmp = nums[i];
            nums [i] = nums[19 - i];
            nums[19 - i] = tmp;
        }
        printf("%d ", nums[i]);
    }
    return 0;
}