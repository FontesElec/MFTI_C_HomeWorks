/*
    В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.
*/

#include <stdio.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 101

int main(void){
    char str[STR_LNG] = {0};
    int ch_cntr = 0;

    
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG,infile);

    for(int i = 0; i < STR_LNG; i++){
        if((str[i] >= ' ') && (str[i] <= '~')){
            ch_cntr++;
        }
        if(str[i] < ' '){
            str[i] = 0;
        }
    }

    for(int i =0; i < 2; i++){
        fprintf(outfile, "%s, ", str);
    }
    fprintf(outfile, "%s ", str);
    fprintf(outfile, "%d", ch_cntr);

    fclose(infile);
    fclose(outfile);
    return 0;
}