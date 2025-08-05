/*
    Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int. 
    Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна.
*/

#include <stdio.h>
#include <limits.h>

#define ARR_LNG 30

int main(void){

    int nums[ARR_LNG] = {0};
    int f_pos = 0;
    int s_pos = 0;
    int f_min = INT_MAX;
    int s_min = INT_MAX;


    for(int i = 0; i < ARR_LNG; i++){
        scanf("%d", nums + i);
    }

    f_min = nums[0];

    for(int i = 1; i < ARR_LNG; i++){
        if(f_min > nums[i]){
            s_min = f_min;
            s_pos = f_pos;
            f_min = nums[i];
            f_pos = i;
        }
        else if(s_min > nums[i]){
            s_min = nums[i];
            s_pos = i;
        }
    }

    f_pos > s_pos ? printf("%d %d", s_pos, f_pos) : printf("%d %d", f_pos, s_pos) ;
    return 0;

}
