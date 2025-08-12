/*
    В файле input.txt записаны символы. Необходимо разработать функцию, которая меняет местами пары соседних символов 
    не обращая внимание на символы пробел. Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. 
    Результат записать в файл output.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1001

int main(void){
    char str[STR_LNG] = {0};
    int cntr = 0;

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");
    char* f_ch;
    char* s_ch;

    //fscanf(infile, "%s", str);
    //fgets(str, STR_LNG, infile);

    fgets(str, STR_LNG, infile);
    
    while((str[cntr] >= ' ') && (cntr < STR_LNG)){
        while ((str[cntr] == ' ') && (cntr < STR_LNG)){
            cntr++;
        }
        if(cntr > STR_LNG){
            break;
        }
        f_ch = &str[cntr];
        cntr++;
        while (str[cntr] == ' '){
            cntr++;
        }
        if(cntr > STR_LNG){
            break;
        }
        s_ch = &str[cntr];
        if(*s_ch <= ' ') {
            break;
        }
        cntr++;
        char tmp = *f_ch;
        *f_ch = *s_ch; 
        *s_ch = tmp;    
    }

    fprintf(outfile, "%s", str);

    //fprintf(outfile, "%c", ' ');

    fclose(infile);
    fclose(outfile);
    return 0;
}