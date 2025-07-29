/*
    Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.
*/
#include <stdio.h>

#define BASE    2       //основание СС (на случай, если потом надо будет переводить и в другие СС)
#if ((BASE > 10) && (BASE < 2))  
    #error (base must be below 10 and above 1)
#endif

//Прототипы функций
void recurs_conv(int num);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    recurs_conv(num);
    return 0;
}

void recurs_conv(int num){
    if(num >= BASE){
        recurs_conv(num / BASE);
    }
    printf("%d", num % BASE);
    return;
}