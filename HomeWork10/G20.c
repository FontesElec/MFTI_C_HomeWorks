/*
    Считать предложение из файла input.txt и определить можно ли из английских букв предложения записанного в файле 
    получить одно слово - палиндром. 
    Ответ напечатать на стандартный поток вывода. Требуется реализовать логическую функцию и применить ее.
    is_palindrom(string)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile;

#define STR_LNG 1001
#define NUM_OF_LETTERS 26

typedef enum{
    FALSE,
    TRUE
}boolean;

boolean is_palindrom(char str[]){
    
    int letters[NUM_OF_LETTERS] = {0};
    int cntr = 0;

    //проходим по всему массиву и считаем число повторений букв
    while(str[cntr] >= ' '){
        //отбрасываем все лишние символы
        if((str[cntr] >= 'a') && (str[cntr] <= 'z')){
            //каждой букве соответствует ячейка массива
            letters[str[cntr] - 'a']++;                 
        }
        cntr++;
    }

    //нужно проверить, что есть всего лишь один символ с нечётным числом повторений, или их нет совсем
    int odd_rep_cntr = 0;
    for(int i = 0; i < NUM_OF_LETTERS; i++){
        if(letters[i] % 2){
            odd_rep_cntr++;
        }
    }

    if((odd_rep_cntr == 1) || (odd_rep_cntr == 0)){
        return TRUE;
    }
    return FALSE;
}

int main(void){
    
    char str[STR_LNG] = {0};

    infile = fopen("input.txt", "r");
    fgets(str, STR_LNG, infile);

    if(is_palindrom(str)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    fclose(infile);
    return 0;
}