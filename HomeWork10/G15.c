/*
    В файле input.txt дано предложение. Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1001

int main(void){
    char word[STR_LNG] = {0};
    char paste[] = "Ling";
    char cut[] ="Cao";

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    //fgets(str, STR_LNG, infile);

    fgets(word, STR_LNG, infile);
    char* res = strstr(word, cut);
    int bias = 0;

    while (res){
        for(int i = 0; i < res - word - bias; i++){
            fprintf(outfile, "%c", word[bias + i]);
        }
        fprintf(outfile, "%s", paste);
        bias = res - word + sizeof(cut) - 1;
        res = strstr(word + bias, cut);
    }

    fprintf(outfile, "%s", word + bias);
    //fprintf(outfile, "%c", ' ');

    fclose(infile);
    fclose(outfile);
    return 0;
}