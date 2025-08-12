/*
    В файле input.txt считать символьную строку, не более 10 000 символов. 
    Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. 
    Учитывать только английские буквы. Результат записать в файл output.txt.
*/

#include <stdio.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 10000

int main(void){
    char str[STR_LNG] = {0};
    int cntr = 0;
    
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG, infile);

    while(str[cntr] >= ' '){
        cntr++;
    }
    
    int small_cntr = 0;
    int large_cntr = 0;
    for(int i =0; i < cntr; i++){
        if((str[i] >= 'a') && (str[i] <= 'z')){
            small_cntr++;
        }
        else if((str[i] >= 'A') && (str[i] <= 'Z')){
            large_cntr++;
        }
    }

    fprintf(outfile, "%d %d", small_cntr, large_cntr);
    fclose(infile);
    fclose(outfile);
    return 0;
}