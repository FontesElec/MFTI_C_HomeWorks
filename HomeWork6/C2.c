/*
    Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования
*/
#include <stdio.h>

//Прототипы функций
int power(int num, int pow);

int main(void){
    int num, pow;
    scanf("%d %d", &num, &pow);
    printf("%d", power(num, pow));
    return 0;
}

int power(int num, int pow){
    int ret = 1;
    if(pow == 0){
        return ret;
    }
    for(int i = 0; i < pow; i++){
        ret *= num;
    }
    return ret;
}