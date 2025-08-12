/*
    Считать число N из файла input.txt. Сформировать строку из N символов. 
    N четное число, не превосходящее 26. 
    На четных позициях должны находится четные цифры в порядке возрастания, кроме 0, 
    на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. 
    Результат записать в файл output.txt
*/

#include <stdio.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 26

int main(void){
    char str[STR_LNG] = {0};
    int num = 0;

    
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    fscanf(infile, "%d", &num);
    //fgets(str, STR_LNG,infile);

    char ch = 'A';
    int step = 0;
    for(int i = 0; i < num; i +=2){
        str[i] = ch;
        ch++;
        str[i + 1] = i + 2 + '0' - step;
        if(i + 2 - step == 8){
            step += 8;
        }
    }


    fprintf(outfile, "%s", str);
    
    fclose(infile);
    fclose(outfile);
    return 0;
}