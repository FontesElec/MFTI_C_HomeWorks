/*
    Переставить цифры в числе так, что бы получилось максимальное число.
*/
#include <stdio.h>
#include <malloc.h>

//Типы данных
typedef enum{
    UP,
    DOWN
}SortOrder;

//Прототипы функций
//Две эти функции ниже вместе описывают алгоритм пузырьковой вставки 
void insertion_sort(int range, int* matrix, SortOrder ord);
void iteration_of_sort(int k, int* matrix, SortOrder ord);



int main(void){
    int* num_ptr;             //указатель на массив с цифрами числа
    int cntr = 0;
    int num = 0;
    scanf("%d", &num);
    {
        int divider = 1;
        while(num / divider != 0){  //считаем число разрядов
            cntr++;
            divider *= 10;
        }
    }
    
    num_ptr = (int*)malloc(cntr * sizeof(int)); //Выделяем место, необходимое для умещения всех цифр
    for(int i = 0; i < cntr; i ++){             //Заполняем массив
        num_ptr[i] = num % 10;
        num /= 10;
    }

    insertion_sort(cntr, num_ptr,DOWN);         //Сортируем по убыванию элементы массива

    num = 0;
    for(int i = 0; i < cntr; i++){              //Можно просто напечатать массив, можно собрать в переменную
       num = num * 10 + num_ptr[i];
    }
    free(num_ptr);                              //Освобождаем выделенный кусок памяти
    printf("%d", num);
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
