/*
    В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом. 
    Найдите только те символы слов, которые встречаются в обоих словах только один раз. 
    Напечатайте их через пробел в файл output.txt в лексикографическом порядке.
*/

#include <stdio.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 100

int main(void){
    char word1[STR_LNG] = {0};
    char word2[STR_LNG] = {0};
        
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    fscanf(infile, "%s %s", word1, word2);
    //fgets(str, STR_LNG, infile);

    for(char ch = '!'; ch < '~'; ch++){
        int en_w1_flag = 0;
        int en_w2_flag = 0;
        int cntr = 0;
        while(word1[cntr] >= '!'){
            if(ch == word1[cntr]){
                en_w1_flag++;
            }
            cntr++;
        }
        cntr = 0;
        while(word2[cntr] >= '!'){
            if(ch == word2[cntr]){
                en_w2_flag++;
            }
            cntr++;
        }
        if((en_w1_flag == 1) && (en_w2_flag == 1)){
            fprintf(outfile, "%c ", ch);
        }
    }
    //fprintf(outfile, "%s", str);
    
    fclose(infile);
    fclose(outfile);
    return 0;
}