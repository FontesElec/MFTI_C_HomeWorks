/*
    Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу.
*/
#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}boolean;

//Прототипы функций
boolean is_even(int num);
int calc_sum_of_digs(int num);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    if(is_even(calc_sum_of_digs(num))){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}

boolean is_even(int num){
    return (boolean)(1 ^ (num % 2));
}

int calc_sum_of_digs(int num){
    int sum = 0;
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
