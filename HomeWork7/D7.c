/*
    Составить рекурсивную функцию, печать всех чисел от N до 1.
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
    printf("%d ", num);
    if(num != 1){
        recurs_print(num - 1);
    }
    return;
}