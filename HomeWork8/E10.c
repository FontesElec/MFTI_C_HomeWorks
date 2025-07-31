/*
    Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.
*/
#include <stdio.h>

#define ARRAY_LNG   12
#define STEP        4

//Переменные
int nums[ARRAY_LNG];

int main(void){
    for(int i = 0; i < ARRAY_LNG; i++){
        //чтобы не пересчитывать индексы и не перебрасывать значения, проще сразу писать в ячейки со смещением адреса на bias
        int bias = i + STEP;    
        if(bias >= ARRAY_LNG){
            bias =  i + STEP - ARRAY_LNG;
        }
        scanf("%d", (nums + bias));
    }

    for(int i = 0; i < ARRAY_LNG; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}