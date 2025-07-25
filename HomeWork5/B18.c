/*
    Числа Фибоначчи
    Используется рекурсия функции sum
*/
#include <stdio.h>

int cntr;

void sum(int first, int second){
    int tmp = first + second;
    printf("%d ",tmp);
    cntr--;
    if(cntr){
        sum(second, tmp);
    }
}

int main(void){

    int n0 = 0, n1 = 1;
    scanf("%d", &cntr);
    printf("%d ", 1);        //для первой единицы проще всего задать просто прямую печать значения
    cntr--;

    if(cntr == 0){
        return 0;
    }

    sum(n0, n1);            //рекурсивный вывод суммы двух предыдцщих значений
    return 0;
}