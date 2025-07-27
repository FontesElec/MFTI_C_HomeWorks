/*
   Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования
*/
#include <stdio.h>

//Прототипы функций
int get_sum(int N);

int main(void){
    int num;
    scanf("%d", &num);
    printf("%d", get_sum(num));
    return 0;
}

int get_sum(int N){
    int sum = 0;
    for(int i = 1; i <= N; i++){
        sum += i;
    }
    return sum;
}