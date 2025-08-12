/*
    Разработать функцию дана строка из маленьких английских букв. Составить из символов палиндром максимальной длинны. 
    При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке. Записать ответ в файл output.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1001
#define NUM_OF_LETTERS 26


int main(void){
    int letters[NUM_OF_LETTERS] = {0};
    char str[STR_LNG] = {0};
    int cntr = 0;

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG, infile);

    //проходим по всему массиву и считаем число повторений букв
    while(str[cntr] >= ' '){
        //отбрасываем все лишние символы
        if((str[cntr] >= 'a') && (str[cntr] <= 'z')){
            //каждой букве соответствует ячейка массива
            letters[str[cntr] - 'a']++;                 
        }
        cntr++;
    }

    //ищем "центр" - букву с максимальным числом нечётных повторений
    int max_repeats = 0;
    int c_letter_pos = 0;

    for(int i = 0; i < NUM_OF_LETTERS; i++){
        if((max_repeats < letters[i]) && (letters[i] % 2)){
            max_repeats = letters[i];
            c_letter_pos = i;
        }
    }

   
    //теперь проходим от a до z и пишем половину от числа повторений и под конец ставим центральную букву
    //затем просто проходим в обратную сторону

    for(int i = 0; i < NUM_OF_LETTERS; i++){
        for(int j = 0; j < letters[i] / 2; j++){
            fprintf(outfile, "%c", (char)(i + 'a'));
        }
    }

    fprintf(outfile, "%c", (char)(c_letter_pos + 'a'));  //центральный символ

    for(int i = NUM_OF_LETTERS - 1; i >= 0; i--){
        for(int j = 0; j < letters[i] / 2; j++){
            fprintf(outfile, "%c", (char)(i + 'a'));
        }
    }
     

    //fprintf(outfile, "%c", ' ');

    fclose(infile);
    fclose(outfile);
    return 0;
}