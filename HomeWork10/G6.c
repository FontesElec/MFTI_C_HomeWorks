/*
    В файле input.txt символьная строка не более 1000 символов. Необходимо проверить, 
    является ли она палиндромом (палиндром читается одинаково в обоих направлениях). 
    Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.
*/

#include <stdio.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1000

int main(void){
    char str[STR_LNG] = {0};
    int cntr = 0;
    
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    fscanf(infile, "%s", str);
    //fgets(str, STR_LNG, infile);

    while(str[cntr] > '!'){
        cntr++;
    }

    cntr--;
    
    for(int i = 0; i < cntr; i++){
        if(str[i] != str[cntr - i]){
            fprintf(outfile, "%s", "NO\n");
            fclose(infile);
            fclose(outfile);
            return 0;
        }
    }

    fprintf(outfile, "%s", "YES\n");
    fclose(infile);
    fclose(outfile);
    return 0;
}