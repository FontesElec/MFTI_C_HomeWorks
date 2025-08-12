/*
    В файле input.txt дана символьная строка не более 1000 символов. 
    Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.
*/

#include <stdio.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1000

int main(void){
    char str[STR_LNG] = {0};
    
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG, infile);

    int cntr = 0;
    while(str[cntr] >= ' '){
        switch (str[cntr]){
            case 'a':{
                str[cntr] = 'b';
                break;
            }
            case 'b':{
                str[cntr] = 'a';
                break;
            }
            case 'A':{
                str[cntr] = 'B';
                break;
            }
            case 'B':{
                str[cntr] = 'A';
                break;
            }
            default: break;
        }
        cntr++;
    }

    fprintf(outfile, "%s", str);
    
    fclose(infile);
    fclose(outfile);
    return 0;
}