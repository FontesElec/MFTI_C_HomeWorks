/*
    Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
*/
#include <stdio.h>

//Прототипы функций
int recurs_sum(int num);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    printf("%d", recurs_sum(num));
    return 0;
}

int recurs_sum(int num){
    if(num != 1){
        return num + recurs_sum(num - 1);
    }
    
    return 1;
}