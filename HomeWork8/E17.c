/*
    Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.
*/
#include <stdio.h>

#define ARRAY_LNG   10


//Переменные
int nums[ARRAY_LNG];
int filtered[ARRAY_LNG];
int flt_cntr;


int main(void){
   
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
    }

    for(int i = 0; i < ARRAY_LNG; i++){
        int ref = nums[i];
        int repeats = 0;
        for(int j = 0; j < ARRAY_LNG; j++){ //прогоняем поиск по всему массиву и считаем, сколько повторов числа ref было
            if(ref == nums[j]){             //одно совпадение в таком случае связано со сравнением с самим собой
                repeats++;
            }
        }
        if(repeats == 1){
            filtered[flt_cntr] = ref;
            flt_cntr++;
        }
    }

    for(int i = 0; i < flt_cntr; i++){
        printf("%d ", filtered[i]);
    }
    
    return 0;
}

