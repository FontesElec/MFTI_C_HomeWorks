/*
    Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, 
    сколько элементов превосходят по модулю максимальный элемент.
    Прототип функции int count_bigger_abs(int n, int a[]);
*/

#include <stdio.h>
#include <limits.h>

int count_bigger_abs(int n, int a[]){
    int max = INT_MIN;
    int cntr = 0;

    for(int i = 0; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i] * a[i] > max * max){
            cntr++;
        }
    }
    return cntr;
}

int main(void){
    return 0;
}
