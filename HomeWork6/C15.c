/*
    Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. 
    Используя данную функцию решить задачу. int grow_up(int n)
*/
#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}boolean;

//Прототипы функций
boolean grow_up(int n);     //взамен int будем использовать boolean, сильно ситуацию не меняет, но выглядит изящнее

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    if(grow_up(num)){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}

boolean grow_up(int n){
    //логика от обратного: проверяем с хвоста что число больше впереди стоящего
    int prev = 10;  //недостижимое значение для одной цифры;
    while(n != 0){
        int tmp = n % 10;
        if(prev <= tmp){
            return FALSE;
        }
        prev = tmp;
        n /= 10;
    }
    return TRUE;
}