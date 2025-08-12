/*
    В файле input.txt дана строка из не более 1000 символов. Показать номера символов, совпадающих с последним символом строки.
    Результат записать в файл output.txt
*/

#include <stdio.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1000

int main(void){
    char str[STR_LNG] = {0};
        
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%d", &num);
    fgets(str, STR_LNG, infile);


    //определяем последний символ
    int cntr = 0;
    while((str[cntr] != 0) && (str[cntr] != '\n')){
        cntr ++;
    }

    char ref = str[cntr - 1];

    //проходим по всему массиву в поиску таких же символов
    for(int i = 0; i < cntr - 1; i++){
        if(str[i] == ref){
            fprintf(outfile, "%d ", i);
        } 
    }


    //fprintf(outfile, "%s", str);
    
    fclose(infile);
    fclose(outfile);
    return 0;
}