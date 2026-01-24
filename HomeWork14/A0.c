/*
        На стандартном потоке ввода задаётся натуральное число N (N > 0), после которого следует последовательность из N целых чисел.
        На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум. Указание: использовать массивы запрещается.
*/

#include <stdio.h>
#include <limits.h>

int iter = 0;               //число итераций
int cur_num = 0;            //текущее значение
int lim_cntr = 0;           //счётчик максимумов
int max_val = INT_MIN;      //текущее максимальное

int main(void){
    
    scanf("%d", &iter);
    
    for(int i = 0; i < iter; i++){

        scanf("%d", &cur_num);
        if(cur_num == max_val){
            lim_cntr++;
        }
        if(cur_num > max_val){
            lim_cntr = 1;
            max_val = cur_num;
        }
    }

    printf("%d", lim_cntr);
    return 0;
}