/*
    Считать массив из 10 элементов и отсортировать его по последней цифре.
*/
#include <stdio.h>

#define ARRAY_LNG   10

//Прототипы функций
//Две эти функции ниже вместе описывают алгоритм пузырьковой вставки 
void insertion_sort(int range, int* matrix);
void iteration_of_sort(int k, int* matrix);

//Переменные
int nums[ARRAY_LNG];

int main(void){
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
    }
    
    insertion_sort(ARRAY_LNG, nums);

    for(int i = 0; i < ARRAY_LNG; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}

void insertion_sort(int range, int* matrix){
    for(int i = 0; i < range - 1; i++){       
        if(matrix[i] % 10 > matrix[i+1] % 10){
            iteration_of_sort(i,matrix);         
        }                  
    }
}


void iteration_of_sort(int k, int* matrix){
    int temp = matrix[k + 1];
    matrix[k + 1] = matrix[k];
    matrix[k] = temp;
    if(k > 0){
        k--;
        if(matrix[k] % 10 > matrix[k+1] % 10){            
            iteration_of_sort(k , matrix);         
        }  
    }        
}
