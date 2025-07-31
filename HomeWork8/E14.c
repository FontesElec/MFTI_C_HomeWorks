/*
    Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более одного раза. 
    В результирующем массиве эти числа не должны повторяться
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
    }
    for(int i = 0; i < ARRAY_LNG - 1; i++){             //проходим по очереди каждое значение и ищем похожее дальше до конца массива
        int ref = nums[i];
        for(int j = i + 1; j <ARRAY_LNG; j++){  
            if(ref == nums[j]){                         //Если нашли похожее
                int cntr = 0;
                while(cntr < flt_cntr){
                    if(ref == filtered[cntr]){          //Ищем то же значение внутри отфильтрованных
                        break;
                    }
                    cntr++;
                }
                //Если значение в отфильтрованных найдено, то индекс cntr на него будет указывать и запись не будет иметь эффекта
                //Иначе индекс будет указывать на первое пустое место
                filtered[cntr] = ref;
                if(cntr == flt_cntr){
                    flt_cntr++;
                }
            }
        }
    }

    for(int i = 0; i < flt_cntr; i++){
        printf("%d ", filtered[i]);
    }
    return 0;
}

