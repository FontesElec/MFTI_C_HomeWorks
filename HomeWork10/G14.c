/*
    В файле input.txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие output.txt, где останутся имя и фамилия
*/

#include <stdio.h>
#include <stdlib.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 101

int main(void){
    char first_name[STR_LNG] = {0};
    char last_name[STR_LNG] = {0};
    
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    //fgets(str, STR_LNG, infile);

    fscanf(infile, "%s %s", last_name, first_name);

    fprintf(outfile, "%s", "Hello, ");
    fprintf(outfile, "%s ", first_name);
    fprintf(outfile, "%s", last_name);
    fprintf(outfile, "%c", '!');
    //fprintf(outfile, "%c", ' ');

    fclose(infile);
    fclose(outfile);
    return 0;
}