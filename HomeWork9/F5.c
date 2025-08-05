/*
    Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
    Прототип функции: int find_max_array(int size, int a[])
*/
#include <stdio.h>

int find_max_array(int size, int a[]){
    int max = -2147483647 - 1;
    for(int i = 0; i < size; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int main(void){
   
    return 0;
}
