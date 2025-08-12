/*
    В файле input.txt записан полный адрес файла (возможно, без расширения). 
    Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.
*/

#include <stdio.h>
#include <stdlib.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1001

int main(void){
    char str[STR_LNG] = {0};
    int cntr = 0;
    int last_slash_pos = 0;
    char ext[] = {".html"};
    

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG, infile);

    while(str[cntr] >= ' '){
        if(str[cntr] == '/'){
            last_slash_pos = cntr;
        }
        cntr++;
    }

    int dot_pos = 0;

    for(int i = last_slash_pos; i < cntr; i++){ //ищем точку с разрешением
        if(str[i] == '.'){
           dot_pos = i;
        }
    }

    if(!dot_pos){   //если точки не было, то дописываем в хвост массива
        dot_pos = cntr;
    }

    for(int i = 0; i < (int)(sizeof(ext) / sizeof(char)); i++){ //дописываем разрешение
        str[dot_pos + i] = ext[i];
    }

    cntr = dot_pos + (int)(sizeof(ext) / sizeof(char));

    while(str[cntr] != 0){  //затираем хвост
        str[cntr] = 0;
        cntr++;
    }
    
    fprintf(outfile, "%s", str);

    //fprintf(outfile, "%c", ' ');
    fclose(infile);
    fclose(outfile);
    return 0;
}