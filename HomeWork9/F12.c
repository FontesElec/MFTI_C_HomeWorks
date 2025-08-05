/*
    Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
    Прототип функции void change_max_min(int size, int a[])
*/

#include <stdio.h>
#include <limits.h>

void change_max_min(int size, int a[]){
    int min = INT_MAX;
    int max = INT_MIN;
    int max_pos = 0;
    int min_pos = 0;

    for(int i = 0; i < size; i++){
        if(a[i] > max){
            max = a[i];
            max_pos = i;
        }
        if(a[i] < min){
            min = a[i];
            min_pos = i;
        }
    }

    a[max_pos] = min;
    a[min_pos] = max;
}

int main(void){
    return 0;
}
