/*
    Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.
    int is2pow(int n)
*/
#include <stdio.h>  

//Типы данных
typedef enum{
    FALSE,
    TRUE
}Boolean;

//Прототипы функций
Boolean is2pow(int n);


int main(void){
    int num;
    scanf("%d", &num);
    if(is2pow(num)){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}

Boolean is2pow(int n){
    if(n == 1){
        return TRUE;
    }
    if((n / 2 > 1) && ((n % 2) == 0)){
        return is2pow(n / 2);
    }
    return (Boolean)((n % 2) ^ 1);
}