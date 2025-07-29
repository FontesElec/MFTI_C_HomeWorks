/*
    Дано натуральное число n ≥ 1. Проверьте, является ли оно простым. Программа должна вывести слово YES, 
    если число простое или NO в противном случае. Необходимо составить рекурсивную функцию и использовать ее.
    int is_prime(int n, int delitel)
*/

#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}Boolean;

//Прототипы функций
Boolean is_prime(int n, int delitel);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    if(is_prime(num, 2)){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}

Boolean is_prime(int n, int delitel){
    if(n ==1){
        return FALSE;
    }
    if(n == delitel){
        return TRUE;
    }
    if(n % delitel != 0){
        return is_prime(n, delitel + 1);
    }
    return FALSE;
}