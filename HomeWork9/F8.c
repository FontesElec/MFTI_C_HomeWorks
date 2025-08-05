/*
    В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке, 
    но одно из чисел пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000. 
    Последовательность заканчивается числом 0. Определить пропущенное число.
*/
#include <stdio.h>
#include <limits.h>


#define ARR_LNG 1000


int main(void){
    int nums[ARR_LNG] = {0};
    int cntr = 0;
    int num = 10;   //произвольное число, не равное нулю
    int enable_flg = 0;
    int min = INT_MAX;
    int max = INT_MIN;

    //наполнение массива
    while(num != 0){
        scanf("%d", &num);
        nums[cntr] = num;
        cntr++;
    }

    //число 0 не входит, поэтому откатим cntr
    cntr--;

    //поиск пределов
    for(int i = 0; i < cntr; i++){
        if(nums[i] > max){
            max = nums[i];
        }
        if(nums[i] < min){
            min = nums[i];
        }
    }

    //проходим по массиву и ищем все значения от min до max по порядку
    for(int i = min; i <= max; i++){
        enable_flg = 0;
        for(int j = 0; j < cntr; j++){
            if(nums[j] == i){
                enable_flg = 1;
            }
        }
        if(enable_flg != 1){
            printf("%d",i);
            return 0;
        }
    }

    return 0;
}
