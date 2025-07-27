/*
    Составить функцию логическую функцию, которая определяет, верно ли, что число простое. Используя функцию решить задачу. int is_prime(int n)
*/
#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}boolean;

//Прототипы функций
boolean is_prime(int n);     //взамен int будем использовать boolean, сильно ситуацию не меняет, но выглядит изящнее

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    if(is_prime(num)){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}


boolean is_prime(int num){
    if((num == 1) || (num == 0)){
        return FALSE;
    }
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return FALSE;
        }
    }
    return TRUE;
}