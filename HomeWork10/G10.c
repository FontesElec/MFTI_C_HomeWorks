/*
    В файле input.txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл output.txt. 
    Случай, когда самых длинных слов может быть несколько, не обрабатывать.
*/

#include <stdio.h>
#include <stdlib.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1001

int main(void){
    char str[STR_LNG] = {0};
    int cntr = 0;
    int max_lng = 0;
    int prev_max_lng = 0;
    int start_idx = 0;
    int max_word_start_idx = 0;

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG, infile);

    while(str[cntr] >= ' '){
        if(str[cntr] == ' '){
            if(cntr - start_idx >= max_lng){
                prev_max_lng = max_lng;
                max_lng = cntr - start_idx;
                max_word_start_idx = start_idx;
            }
            start_idx = cntr + 1;
        }
        cntr++;
    }

    if(max_lng > prev_max_lng){
        for(int i = 0; i < max_lng; i++){
            fprintf(outfile, "%c", str[max_word_start_idx + i]);
        }        
    }
    if(max_lng == 0){
        fprintf(outfile, "%s", str);
    }

    //fprintf(outfile, "%c", ' ');
    fclose(infile);
    fclose(outfile);
    return 0;
}