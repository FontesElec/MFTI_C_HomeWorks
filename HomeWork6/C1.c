/*
    Составить функцию, модуль числа и привести пример ее использования
*/
#include <stdio.h>

//Прототипы функций
int make_abs(int num);

int main(void){
    int num;
    scanf("%d", &num);
    printf("%d", make_abs(num));
    return 0;
}

int make_abs(int num){
    if(num < 0){
        num = -num;
    }
    return num;
}