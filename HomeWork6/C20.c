/*
    Составить функцию, которая преобразует текущий символ цифры в число. Написать программу считающую сумму цифр в тексте. int digit_to_num(char c)
*/
#include <stdio.h>

//Переменные
unsigned char ch;
unsigned int opened_bracket = 0;
unsigned int closed_bracket = 0;

int main(void){
    while(1){
        scanf("%c", &ch);
        if(ch == '.'){
            break;
        }
        if(ch == '('){
            opened_bracket++;
        }
        if(ch == ')'){
            if(opened_bracket){
                closed_bracket++;
            } 
        }
    }
    if(closed_bracket == opened_bracket){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}
