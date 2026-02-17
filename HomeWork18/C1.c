/*
    На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки. 
    Каждая из строк не превышает по длине 10000 символов. В строках не встречаются пробельные символы. 
    На стандартный поток вывода напечатайте два числа, разделённых пробелом: 
    первое число — длина наибольшего префикса первой строки, являющегося суффиксом второй; 
    второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксом второй. 
    Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ARR_LNG 1000

uint16_t find_first_in_sec(char* f_line, char* s_line){
    uint16_t f_line_cap = 0;
    uint16_t s_line_cap = 0;
    uint16_t res = 0;    
    uint16_t cntr = 0;

    //Поиск длины сообщений
    while(f_line[cntr] != '\0'){
        cntr++;
    }
    f_line_cap = cntr;
    cntr = 0;
    while(s_line[cntr] != '\0'){
        cntr++;
    }
    s_line_cap = cntr;

    //В качестве счётчика будет наименьшее из длин
    if(f_line_cap > s_line_cap){
        cntr = s_line_cap;
    }
    else{
        cntr = f_line_cap;
    }

    while(cntr){
        //Ищем совпадающий входной символ
        if(f_line[0] != s_line[s_line_cap - cntr]){
            cntr--;
        }
        else{
            //Если нашли совпадение, то проверяем, совпадают ли остальные символы
            uint8_t not_matched = 0;
            for(uint16_t i = 0; i < cntr; i++){
                if(f_line[i] != s_line[s_line_cap - cntr + i]){
                    not_matched = 1;
                    cntr--;
                    break;
                }
            }
            //Если найдено несовпадение, то возвращаемся к поиску совпадения первых букв
            if(!not_matched){
                res = cntr;
                break;
            }
        }

    }
    return res;
}

int main(void){
    char f_line[ARR_LNG] = {'\0'};
    char s_line[ARR_LNG] = {'\0'};

    uint16_t lng_first_in_sec = 0, lng_sec_in_first = 0;
  
    scanf("%s", f_line);
    scanf("%s", s_line);

    lng_first_in_sec = find_first_in_sec(f_line, s_line);
    lng_sec_in_first = find_first_in_sec(s_line, f_line);

    printf("%d %d", lng_first_in_sec, lng_sec_in_first);
}