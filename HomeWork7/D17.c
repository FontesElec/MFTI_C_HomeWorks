/*
    Функция Аккермана определяется рекурсивно для неотрицательных целых чисел m и n следующим образом:
    Реализуйте данную функцию по прототипу
    int akkerman(int m, int n)
*/
#include <stdio.h>  

//Прототипы функций
int akkerman(int m, int n);


int main(void){
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d", akkerman(m, n));
    return 0;
}

int akkerman(int m, int n){
    if(m == 0){
        return n + 1;
    }
    else if(n == 0){
        return akkerman(m - 1, 1);
    }
    return akkerman(m - 1, akkerman(m, n -1));
}