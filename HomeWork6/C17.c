/*
    Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению. int is_happy_number(int n)
*/
#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}boolean;

//Прототипы функций
boolean is_happy_number(int n);     //взамен int будем использовать boolean, сильно ситуацию не меняет, но выглядит изящнее

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    if(is_happy_number(num)){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}


boolean is_happy_number(int num){
    int sum = 0;
    int prod = 1;
    while(num != 0){
        int tmp = num % 10;
        sum += tmp;
        prod *= tmp;
        num /= 10;
    }
    return (boolean)(sum == prod);
}