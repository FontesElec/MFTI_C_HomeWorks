/*
    Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа. void print_simple(int n)
*/
#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}boolean;

//Прототипы функций
void print_simple(int n);
boolean is_simple(int num);

//Переменные
int num;

int main(void){
    scanf("%d", &num);
    print_simple(num); 
    return 0;
}


/*
    Запускаем счётчик, который будет делителем.
    Проверяем что очередное число счётчика является простым числом и если это так, 
    то проверяем, делится ли число на это значение счётчика.
    Если делится, то пишем в поток и делим значение, если нет, то инкрементируем счётчик и продолжаем поиск
*/
void print_simple(int n){
    int cntr = 2; 
    //по логике работы этой программы счётчик будет крутиться ровно до момента 
    //пока он одновременно не станет равен числу и не будет его наибольшим простым множетилем
    while(n >= cntr){     
        if(is_simple(cntr) && (n % cntr == 0)){
            printf("%d ", cntr);
            n /= cntr;
        }
        else{
            cntr++;
        }
    }
}

boolean is_simple(int num){
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