/*
    В диапазоне натуральных чисел от 2 до N определить, сколько из них кратны любому из чисел в диапазоне от 2 до 9.
*/
#include <stdio.h>

#define ARRAY_LNG   10


//Переменные
//int dividers[ARRAY_LNG];
int flt_cntr;
int num;


int main(void){

    scanf("%d", &num);
    
    for(int i = 2; i <= 9; i++){
        int cntr = 0;
        for(int j = 2; j <= num; j++){
            if(j % i == 0){
                cntr++;
            }
        }
        //dividers[i - 2] = cntr;
        printf("%d ", i);
        printf("%d\n", cntr);
    }
    
    return 0;
}

