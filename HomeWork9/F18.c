/*
    Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм вычисления суммы максимальных элементов из каждой строки. 
    Напечатать значение этой суммы. Предполагается, что в каждой строке такой элемент единственный. 
    Реализовать функцию поиска максимума в строке из 10 элементов
*/

#include <stdio.h>
#include <limits.h>

#define MATRIX_LENGTH   10
#define MATRIX_HEIGHT   10

int find_max_in_row(int size){
    int max = INT_MIN;
    int num = 0;

    for(int i = 0; i < size; i++){
        scanf("%d", &num);
        if(num > max){
            max = num;
        }
    }
    return max;
}

int main(void){
    int sum = 0;
    for(int i = 0; i < MATRIX_HEIGHT; i ++){
        sum += find_max_in_row(MATRIX_LENGTH);
    }
    printf("%d", sum);
    return 0;
}
