/*
    Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.
    **за основу взята D5 с небольшими изменениями
*/
#include <stdio.h>

#define BASE    2       //основание СС (на случай, если потом надо будет переводить и в другие СС)
#if ((BASE > 10) && (BASE < 2))  
    #error (base must be below 10 and above 1)
#endif

//Прототипы функций
void recurs_conv(int num, int* cntr);

//Переменные
int num;


int main(void){
    int cntr = 0;
    scanf("%d", &num);
    recurs_conv(num, &cntr);
    printf("%d", cntr);
    return 0;
}

void recurs_conv(int num, int* cntr){
    if(num >= BASE){
        recurs_conv(num / BASE, cntr);
    }
    *cntr +=  num % BASE;
    return;
}