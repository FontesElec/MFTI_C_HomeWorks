/*
    В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. Ответ записать в файл output.txt.
*/

#include <stdio.h>
#include <stdlib.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1001

int main(void){
    char str[STR_LNG] = {0};
    int cntr = 0;
    int a_cntr = 0;
    

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG, infile);

    while(str[cntr] >= ' '){
        if(str[cntr] == ' '){
            if((str[cntr - 1] == 'a') && (cntr > 0)){
                a_cntr++;
            }
        }
        cntr++;
    }

    if((a_cntr == 0) && (str[cntr - 1] == 'a')){
        a_cntr = 1;
    }

    fprintf(outfile, "%d", a_cntr);

    //fprintf(outfile, "%c", ' ');
    fclose(infile);
    fclose(outfile);
    return 0;
}