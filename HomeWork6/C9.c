/*
    Составить функцию вычисления N!. Использовать ее при вычислении факториала int factorial(int n)
*/
#include <stdio.h>


//Прототипы функций
int factorial(int n);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    printf("%d", factorial(num));    
    return 0;
}

int factorial(int n){
    int ret = 1;
    for(int i = 1; i <= n; i++){
        ret *= i;
    }
    return ret;
}