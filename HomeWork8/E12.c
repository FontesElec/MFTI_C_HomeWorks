/*
    Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.
*/
#include <stdio.h>

#define ARRAY_LNG   10

//Типы данных
typedef enum{
    UP,
    DOWN
}SortOrder;

//Прототипы функций
//Две эти функции ниже вместе описывают алгоритм пузырьковой вставки 
void insertion_sort(int range, int* matrix, SortOrder ord);
void iteration_of_sort(int k, int* matrix, SortOrder ord);

//Переменные
int nums[ARRAY_LNG];

int main(void){
    for(int i = 0; i < ARRAY_LNG; i++){
        scanf("%d", (nums + i));
    }
    
    insertion_sort(ARRAY_LNG / 2, nums, UP);
    insertion_sort(ARRAY_LNG / 2, nums + (ARRAY_LNG / 2), DOWN);

    for(int i = 0; i < ARRAY_LNG; i++){
        printf("%d ", nums[i]);
    }
    return 0;
}

void insertion_sort(int range, int* matrix, SortOrder ord){
    for(int i = 0; i < range - 1; i++){  
        if(ord == UP){
            if(matrix[i] > matrix[i+1] ){
                iteration_of_sort(i, matrix, ord);         
            }       
        }
        else{
            if(matrix[i] < matrix[i+1] ){
                iteration_of_sort(i, matrix, ord);         
            }  
        }  
                   
    }
}


void iteration_of_sort(int k, int* matrix, SortOrder ord){
    int temp = matrix[k + 1];
    matrix[k + 1] = matrix[k];
    matrix[k] = temp;
    
    if(k > 0){
        k--;
        if(ord == UP){
            if(matrix[k] > matrix[k+1] ){            
                iteration_of_sort(k , matrix, ord);         
            } 
        } 
        else{
            if(matrix[k] < matrix[k+1] ){            
                iteration_of_sort(k , matrix, ord);         
            } 
        }
    }    
}
