/*
    Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. 
    Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот void reverse_string()
*/
#include <stdio.h>

//Прототипы функций
void reverse_string(void);

int main(void){
    reverse_string();
    return 0;
}

void reverse_string(void){
    char ch;
    scanf("%c", &ch);
    if(ch == '.'){
        return;
    }
    reverse_string();
    printf("%c", ch);
}