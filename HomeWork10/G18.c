/*
    В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы). 
    Для решения задачи разработать функцию. Результат записать в output.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1001

void del_spaces(FILE* in, FILE* out){
    char str[STR_LNG] = {0};

    while(fscanf(in, "%s", str) != EOF){
        fprintf(out, "%s ", str);
    }
}

int main(void){
    
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    //fgets(str, STR_LNG, infile);

    del_spaces(infile, outfile);
    
    //fprintf(outfile, "%c", ' ');

    fclose(infile);
    fclose(outfile);
    return 0;
}