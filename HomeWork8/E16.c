/*
    Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.
*/
#include <stdio.h>

#define ARRAY_LNG   10


//Переменные
int nums[ARRAY_LNG];
int max_repeats = 0;
int res_num;


int main(void){
   
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
    }

    for(int i = 0; i < ARRAY_LNG - 1; i++){
        int ref = nums[i];
        int repeats = 0;
        for(int j = i; j < ARRAY_LNG; j++){ //прогоняем поиск по всему массиву и считаем, сколько повторов числа ref было
            if(ref == nums[j]){
                repeats++;
                if(repeats > max_repeats){  //если повторов больше максимума, обновляем значение
                    res_num = ref;
                    max_repeats = repeats;
                }
            }
        }
    }

    printf("%d", res_num);
    
    return 0;
}

