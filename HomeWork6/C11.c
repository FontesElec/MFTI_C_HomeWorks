/*
    Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования. int nod(int a, int b)
*/
#include <stdio.h>

//Прототипы функций
int nod(int a, int b);

//Переменные
int num1, num2;

int main(void){
    scanf("%d %d", &num1, &num2);
    printf("%d", nod(num1, num2));
    return 0;
}

//Копия задания B16 c алгоритмом Евклида
int nod(int a, int b){
    while(b!= 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    //согласно алгоритму a будет содержать НОД
    return a;
}