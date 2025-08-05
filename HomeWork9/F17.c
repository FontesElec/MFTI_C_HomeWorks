/*
    Составить функцию которая находит след матрицы в двумерном массиве. Показать пример ее работы на матрице из 5 на 5 элементов. 
    След матрицы - это сумма элементов на главной диагонали.
*/

#include <stdio.h>

#define MATRIX_LENGTH   5
#define MATRIX_HEIGHT   5


int main(void){

    //Программу можно собрать и без матрицы, главное просто отбросить ненужные значения на лету и суммировать нужные
    //int matrix[MATRIX_HEIGHT][MATRIX_LENGTH] = {0,0};
    int num = 0;
    int sum = 0;

    for(int i = 0; i < MATRIX_HEIGHT; i++){
        for(int j = 0; j < MATRIX_LENGTH; j++){
            scanf("%d", &num);
            if(i == j){
                sum += num;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
