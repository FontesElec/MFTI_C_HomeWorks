/*
    Составить логическую функцию, которая определяет, что текущий символ это цифра. 
    Написать программу считающую количество цифр в тексте. int is_digit(char c)
*/
#include <stdio.h>

//Типы данных
typedef enum{
    FALSE,
    TRUE
}boolean;

//Прототипы функций
boolean is_digit(char c);     //взамен int будем использовать boolean, сильно ситуацию не меняет, но выглядит изящнее

//Переменные
unsigned char ch;
unsigned int cntr = 0;

int main(void){
    while(1){
        scanf("%c", &ch);
        if(ch == '.'){
            break;
        }
        if(is_digit(ch)){
            cntr++;
        }
    }
   
    printf("%d", cntr);
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