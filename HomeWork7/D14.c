/*
    Дана последовательность целых чисел через пробел, завершающаяся числом 0. 
    Выведите все нечетные числа из этой последовательности, сохраняя их порядок.Составить рекурсивную функцию, 
    печать всех простых множителей числа
*/
#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}Boolean;

//Прототипы функций
Boolean is_odd(int num);
void print_odd(void);


int main(void){
    print_odd();
    return 0;
}

Boolean is_odd(int num){
    return (Boolean)(num % 2);
}

void print_odd(void){
    int num;
    scanf("%d", &num);
    if(num == 0){
        return;
    }
    if(is_odd(num)){
        printf("%d ", num);
    }
    print_odd();
}
