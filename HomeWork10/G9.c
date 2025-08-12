/*
    В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов. 
    Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.
*/

#include <stdio.h>
#include <stdlib.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1000

int main(void){
    char str[STR_LNG] = {0};
    char filtered[STR_LNG] = {0};
    int cntr = 0;
    int fliter_idx = 0;

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG, infile);

    while(str[cntr] >= ' '){
        if(str[cntr] != ' '){
            int not_matched = 1;
            for(int i = 0; i < fliter_idx; i++){
                if(filtered[i] == str[cntr]){
                    not_matched = 0;
                    break;
                }
            }
            if(not_matched){
                filtered[fliter_idx] = str[cntr];
                fliter_idx++;
            }
        }
        cntr++;
    }

    for(int i = 0; i < fliter_idx; i++){
        fprintf(outfile, "%c", filtered[i]);
    }

    //fprintf(outfile, "%c", ' ');
    fclose(infile);
    fclose(outfile);
    return 0;
}