/*
    В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. 
    Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. 
    Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. 
    Вывести массив по возрастанию в файл output.txt.
*/

#include <stdio.h>
#include <stdlib.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 10000

void sort_array(int size, int a[]){
    //проходим по массиву и перемещаем меньшие значения на более младшие позиции
    for(int i = 0; i < size - 1; i++){ 
        if(a[i] > a[i + 1]){
            int tmp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = tmp;
        }
    }
    //проверяем, что теперь все значения по возрастанию, если нет, то запускаем повторную сортировку
    for(int i = 0; i < size - 1; i++){
        if(a[i] > a[i + 1]){
            sort_array(size, a);
        }
    }
}

int is_digit(char ch){
    if((ch >= '0') && (ch <= '9')){
        return 1;
    }
    return 0;
}

int main(void){
    char str[STR_LNG] = {0};
    int nums[STR_LNG] = {0};
    int cntr = 0;
    int nums_idx = 0;


    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    fgets(str, STR_LNG, infile);

    while(str[cntr] >= ' '){

        if((str[cntr] >= '0') && (str[cntr] <= '9')){
            char* ch_ptr;
            int num = strtol(str + cntr, &ch_ptr, 10);
            nums[nums_idx] = num;
            nums_idx++;
            cntr = ch_ptr - str - 1;    //если конвертация прошла успешна, то смещаем счётчик на последний сконвертированный символ 
        }

        cntr++;
    }
    
    sort_array(nums_idx, nums);

    for(int i = 0; i < nums_idx; i++){
        fprintf(outfile, "%d ", nums[i]);
    }
    //fprintf(outfile, "%c", ' ');
    fclose(infile);
    fclose(outfile);
    return 0;
}