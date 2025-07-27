/*
   Описать функцию вычисления f(x) по формуле:
    f(x)= x*x при -2 ≤ x < 2;
    x*x+4x+5 при x ≥ 2;
    4 при x < -2.
    Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.
*/
#include <stdio.h>

//Прототипы функций
int get_solvig(int x);

int main(void){
    int max_ans = 0;        //исходя из анализа системы уравнений, минимально возможным решением уравнения будет 0
    int x;
    while(1){               //гоняем в бесконечном цикле пока не получим 0
        scanf("%d", &x);
        if(x == 0){
            break;          //Здесь вылетаем из цикла при получении нуля
        }
        int tmp = get_solvig(x);
        if(max_ans < tmp){
            max_ans = tmp;
        }
    }
    printf("%d", max_ans);
    return 0;
}

int get_solvig(int x){
    if(x < -2){
        return 4;
    }
    if(x >= 2){
        return x * x + 4 * x + 5;
    }
    return x * x;
}