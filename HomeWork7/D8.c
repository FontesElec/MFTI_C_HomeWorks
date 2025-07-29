/*
    Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, 
    если A < B, или в порядке убывания в противном случае
*/

#include <stdio.h>

//Прототипы функций
void recurs_print(int num1, int num2);

//Переменные
int num1, num2;

int main(void){
    scanf("%d %d", &num1, &num2);
    recurs_print(num1, num2);
    return 0;
}

void recurs_print(int num1, int num2){
    if(num1 < num2){
        printf("%d ", num1);
        recurs_print(num1 + 1, num2);
        return;
    }
    if(num1 > num2){
        printf("%d ", num1);
        recurs_print(num1 - 1, num2);
        return;
    }
    printf("%d", num1);
    return;
}   