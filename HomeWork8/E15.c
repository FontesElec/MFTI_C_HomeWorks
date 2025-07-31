/*
    Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, 
    во второй - только отрицательные. Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.
*/
#include <stdio.h>

#define ARRAY_LNG   10


//Переменные
int pos_nums[ARRAY_LNG];
int neg_nums[ARRAY_LNG];
int pos_cntr = 0;
int neg_cntr = 0;

int main(void){
    for(int i = 0; i < ARRAY_LNG; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp > 0){
            pos_nums[pos_cntr] = tmp;
            pos_cntr++;
        }
        if(tmp < 0){
            neg_nums[neg_cntr] = tmp;
            neg_cntr++;
        }        
    }
    for(int i = 0; i < pos_cntr; i++){
        printf("%d ", pos_nums[i]);
    }
    for(int i = 0; i < neg_cntr; i++){
        printf("%d ", neg_nums[i]);
    }
    
    
    return 0;
}

