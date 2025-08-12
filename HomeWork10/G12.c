/*
    В файле input.txt дано предложение требуется разобрать его на отдельные слова. 
    Напечатать каждое слово на отдельной строке в файл output.txt.
*/

#include <stdio.h>
#include <stdlib.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1001

int main(void){
    char str[STR_LNG] = {0};
    int start_w_pos = 0;
    int w_length = 0;
    int cntr = 0;
    

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG, infile);

    while(str[cntr] >= ' '){
        if(str[cntr] == ' '){
            for(int i = 0; i < w_length; i++){
                fprintf(outfile, "%c", str[start_w_pos + i]);
                //fprintf(outfile, "%s\n", str + start_w_pos + i);
            }
            if(w_length > 0){
                fprintf(outfile, "%c", '\n'); 
            }            
            w_length = 0;
            start_w_pos = cntr + 1;
        }
        else{
            w_length++;
        }
        cntr++;
    }
    for(int i = 0; i < w_length; i++){
        fprintf(outfile, "%c", str[start_w_pos + i]);
    }


    //fprintf(outfile, "%c", ' ');
    fclose(infile);
    fclose(outfile);
    return 0;
}