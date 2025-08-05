/*
    Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива.
    Прототип функции int count_between(int from, int to, int size, int a[])
*/

#include <stdio.h>

int count_between(int from, int to, int size, int a[]){
    int cntr = 0;
    for(int i = 0; i < size; i++){
        if((a[i] >= from) && (a[i] <= to)){
            cntr++;
        }
    }
    return cntr;
}

int main(void){
    return 0;
}
