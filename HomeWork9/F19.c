/*
    Определить количество положительных элементов квадратной матрицы, 
    превышающих по величине среднее арифметическое всех элементов главной диагонали. 
    Реализовать функцию среднее арифметическое главной диагонали.
*/

#include <stdio.h>
#include <limits.h>

#define MATRIX_LENGTH   5
#define MATRIX_HEIGHT   5


int main(void){

    int matrix[MATRIX_HEIGHT][MATRIX_LENGTH] = {0};
    int sum = 0;
    float avg = 0;
    int cntr = 0;

    for(int i = 0; i < MATRIX_HEIGHT; i++){
        for(int j = 0; j < MATRIX_LENGTH; j++){
            scanf("%d", matrix[i] + j);
            if(i == j){
                sum += *(matrix[i] + j);
            }
        }
    }

    avg = (float)sum / (float)MATRIX_LENGTH;

    for(int i = 0; i < MATRIX_HEIGHT; i++){
        for(int j = 0; j < MATRIX_LENGTH; j++){
            if((matrix[i][j] > 0) && (matrix[i][j] > avg)){
                cntr++;
            }
        }
    }

    printf("%d", cntr);
    return 0;
}
