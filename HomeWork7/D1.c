/*
    Составить рекурсивную функцию, печать всех чисел от 1 до N
*/
#include <stdio.h>

//Прототипы функций
void recurs_print(int num);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    recurs_print(num);
    return 0;
}

void recurs_print(int num){
    if(num != 1){
        recurs_print(num - 1);
    }
    printf("%d ", num);
    return;
}