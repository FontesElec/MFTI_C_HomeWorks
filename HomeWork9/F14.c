/*
    Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
    Прототип функции int sum_between_ab(int from, int to, int size, int a[])
*/

#include <stdio.h>

int sum_between_ab(int from, int to, int size, int a[]){
    int sum = 0;

    if(from > to){
        int tmp = from;
        from = to;
        to = tmp;
    }
    for(int i = 0; i < size; i++){
        if((a[i] >= from) && (a[i] <= to)){
            sum += a[i];
        }
    }
    return sum;
}

int main(void){
    return 0;
}
