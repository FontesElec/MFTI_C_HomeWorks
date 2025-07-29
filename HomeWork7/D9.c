/*
    Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию int sum_digits(int n)
*/

#include <stdio.h>

//Прототипы функций
int sum_digits(int num);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    
    printf("%d", sum_digits(num));
    return 0;
}

int sum_digits(int num){
    int res = num % 10;
    if(num >= 10){
        res += sum_digits(num / 10);
        return res;
    }
    return res;
}