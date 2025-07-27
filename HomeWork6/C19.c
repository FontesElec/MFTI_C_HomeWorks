/*
    Составить функцию, которая преобразует текущий символ цифры в число. Написать программу считающую сумму цифр в тексте. int digit_to_num(char c)
*/
#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}boolean;

//Прототипы функций
boolean is_digit(char c);     //взамен int будем использовать boolean, сильно ситуацию не меняет, но выглядит изящнее
int digit_to_num(char c);

//Переменные
unsigned char ch;
unsigned int sum = 0;

int main(void){
    while(1){
        scanf("%c", &ch);
        if(ch == '.'){
            break;
        }
        if(is_digit(ch)){
            sum += digit_to_num(ch);
        }
    }
   
    printf("%d", sum);
    return 0;
}

boolean is_digit(char c){

    const unsigned char LOWER_RANGE = '0' - 1;
    const unsigned char UPPER_RANGE = '9' + 1;

    if((c > LOWER_RANGE) && (c < UPPER_RANGE)){
        return TRUE;
    }

    return FALSE;
}

int digit_to_num(char c){
    return (int)(c - '0');
}