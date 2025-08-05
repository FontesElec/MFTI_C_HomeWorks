/*
    Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых. 
    Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
    int is_two_same(int size, int a[]);
*/
#include <stdio.h>

int is_two_same(int size, int a[]){
    for(int i = 0; i < size - 1; i++){
        int ref = a[i];
        for(int j = i + 1; j < size; j++){
            if(ref == a[j]){
                return 1;
            }
        }
    }
    return 0;
}

int main(void){
   
    return 0;
}
