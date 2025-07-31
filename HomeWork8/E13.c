/*
    Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.
*/
#include <stdio.h>

#define ARRAY_LNG   10


//Переменные
int nums[ARRAY_LNG];
int filtered[ARRAY_LNG];
int flt_cntr = 0;           //счётчик числа добавленных значений в filtered

int main(void){
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
        if((nums[i] / 10) % 10 == 0){
            filtered[flt_cntr] = nums[i];
            flt_cntr++;
        }
    }
    for(int i = 0; i < flt_cntr; i++){
        printf("%d ", filtered[i]);
    }
    return 0;
}

