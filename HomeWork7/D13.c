/*
    Составить рекурсивную функцию, печать всех простых множителей числа
*/
#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}Boolean;

//Прототипы функций
void print_simple(int n, int cntr);
Boolean is_simple(int num);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    print_simple(num, 2); 
    return 0;
}

void print_simple(int n, int cntr){
    if(n < 2){  //по сути отсекаем, что  n == 1 (пытались найти делители единицы) и n == 0 (всё число было разделено на простые делители), 
        return;
    }
    if(is_simple(cntr) && (n % cntr == 0)){     //если число простое и на него делится без остатка делимое
        printf("%d ", cntr);                    //выводим значение делителя
        print_simple(n / cntr, cntr);           //и отправляем значение, уменьшенное на делитель (мало ли оно может повторно делиться на то же число)
        return;
    }
    //если не сработают ветки выше, то значит, либо делитель - не простое число, либо число не делится без остатка
    //поэтому оставляем число, но увеличиваем значение делителя
    print_simple(n, cntr + 1);
    return;
}




Boolean is_simple(int num){
    if((num == 1) || (num == 0)){
        return FALSE;
    }
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return FALSE;
        }
    }
    return TRUE;
}