/*
    Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров). int middle(int a, int b)
*/
#include <stdio.h>

//Прототипы функций
int middle(int a, int b);

int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%d", middle(num1, num2));
    return 0;
}

int middle(int a, int b){
    return ((a + b) / 2);
}