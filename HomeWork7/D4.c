/*
    Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. 
    Необходимо реализовать рекурсивную функцию void print_num(int num)
*/
#include <stdio.h>

//Прототипы функций
void recurs_print(int num);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    if(!num){
        printf("%d", num);
    }
    recurs_print(num);
    return 0;
}

void recurs_print(int num){
    if(num != 0){
        recurs_print(num / 10);
        printf("%d ", num % 10);
        return;
    }
}