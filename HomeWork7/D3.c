/*
    Дано целое не отрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками
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
        printf("%d ", num % 10);
        recurs_print(num / 10);
        return;
    }
}