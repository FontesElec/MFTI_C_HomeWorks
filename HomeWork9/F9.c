/*
    Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива.
    Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. 
    Если отрицательных элементов нет - массив не менять.
    Прототип функции: void swap_negmax_last(int size, int a[])
*/
#include <stdio.h>
#include <limits.h>

void swap_negmax_last(int size, int a[]){
    int negmax = INT_MIN;
    int negmax_pos = 0;
    int negmax_flg = 0;

    for(int i = 0; i < size; i++){
        if((a[i] < 0) && (a[i] > negmax)){
            negmax_pos = i;
            negmax = a[i];
            negmax_flg = 1;
        }
    }

    if(negmax_flg){
        int tmp = a[size - 1];
        a[size - 1] = a[negmax_pos];
        a[negmax_pos] = tmp;
    }
}


int main(void){

    return 0;
}
