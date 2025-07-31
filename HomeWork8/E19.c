/*
    Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.
*/
#include <stdio.h>

#define ARRAY_LNG   10


//Переменные
void recurse_print(int num);
int flt_cntr;
int num;


int main(void){
    scanf("%d", &num);
    recurse_print(num);
    return 0;
}

void recurse_print(int num){
    if(num > 9){
        recurse_print(num / 10);
    }
    printf("%d ", num % 10);
}