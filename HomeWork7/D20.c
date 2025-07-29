/*
    Написать рекурсивную функцию возведения целого числа n в степень p.
    int recurs_power(int n, int p)
    Используя данную функцию, решить задачу.
*/
#include <stdio.h>  

//Прототипы функций
int recurs_power(int n, int p);


int main(void){
    int num, pow;
    scanf("%d %d", &num, &pow);
    printf("%d", recurs_power(num, pow));
    return 0;
}


int recurs_power(int n, int p){
    if(p == 0){
        return 1;
    }
    return n * recurs_power(n, p - 1);
}