#include <stdio.h>
#include "solving.h"
#include <string.h>

//Конфигурация поведения программы (флаги)
extern struct flags config;

void print_help(void){
    printf("\n-----------------------Flags:-----------------------\n");
    printf("-h or -help will return list off available commands\n");
    printf("-a will return abscisses of crossing functions\n");
    printf("-i will return cuantity of operations by finding rootes\n");
    printf("-s will return result of square calculation\n");
    printf("-tr(a b) will return founded root between a and b\n");
    printf("-ti(a b) will return result of operation by finding scuare of figure between a and b\n");
    printf("if no flags sent, program execute test function without additional information\n");
    printf("\n----------------------------------------------------\n");
}

void parse_command(char** com, int i){
    if(!strcmp("-h", com[i])){
        //printf("called help\n");
        print_help();
    }
    else if(!strcmp("-help", com[i])){
        //printf("called help\n");
        print_help();
    }
    else if(!strcmp("-a", com[i])){
        config.absc = 1;
        //printf("called absc\n");
    }
    else if(!strcmp("-i", com[i])){
        config.iters = 1;
        //printf("called iters\n");
    }
    else if(!strcmp("-s", com[i])){
        config.square = 1;
        //printf("called square\n");
    }
    else if(!strcmp("-tr", com[i])){
        //printf("called test roots\n");
        test_roots(i, com);
    }
    else if(!strcmp("-ti", com[i])){
        //printf("called test integral\n");
        test_integral(i, com);
    }
}


int main(int argc, char* argv[]){
    if(argc == 1){
        test_program();
        return 0;
    }
    else{
        for(int i = 1; i < argc; i++){
            //обрабатываем параметры командной строки
            if(*(argv[i]) == '-'){
                parse_command(argv, i);
            }
            //если параметром не является ключ, то просто игнорируем (прочиаются внутри вызываемой флагом функции)
            else{
                i++;
            }
        }
    }
    //Если задан хоть один флаг по выводу данных, то запустим тестовую программу
    //Условие задано для того, чтобы не запускать общий тест при вызове теста поиска корней или интеграла
    if(config.absc || config.iters || config.square){
        test_program();
    }
    getchar();
    return 0;
}