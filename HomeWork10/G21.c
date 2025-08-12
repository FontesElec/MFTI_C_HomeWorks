/*
    Cia очень любит равносторонние треугольники. Он все время выкладывает их из камней. 
    Ling дал Cia камни и попросил его составить такой треугольник если это возможно. 
    Помогите Cia сложить треугольник используя все камни или напечатайте слов NO, если это невозможно. 
    Пример треугольников, которые составляет Cia:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 1001
#define NUM_OF_LETTERS 26


int main(void){
    
    char str[STR_LNG] = {0};
    int star_cntr = 0;
    
    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    //fgets(str, STR_LNG, infile);

    //считаем звёзды
    while(fgets(str, STR_LNG, infile)){
        int cntr = 0;
        while(str[cntr] > 0){
            if(str[cntr] == '*'){
                star_cntr++;
            }
            cntr++;
        }
    }

    /*
        Определяем, подходит ли число для сборки
        Общая формула ряда: y = x * (x + 1) / 2
        Последовательно перебираем ряд до значения y большего и равного числу звёзд
    */
    int triangle_num = 1;
    int iter = 1;
    while(triangle_num < star_cntr){
        triangle_num = iter * (iter + 1) / 2;
        iter++;
    }

    iter--; //т.к. проскакиваем до отслеживания условия

    //если число звёзд совпадает с треугольным, тогда бдем рисовать треугольник, иначе игнорируем
    if(triangle_num == star_cntr){
        /*
            число пробелов перед "вершиной" на один меньше числа строк
            каждый следующий элемент стороны смещается на единицу ближе к левому краю и длится на 2 больше предыдущего
            число "строк" в треугольнике равно числу итераций

        */
        for(int row = 0; row < iter; row++){
            //заполняем пробелами начало
            for(int spaces = 0; spaces < iter - 1 - row; spaces++){
                fprintf(outfile,"%c", ' ');
            }
            //заполняем звёздами оставшееся пространство
            for(int stars = 0; stars <= row; stars++){
                fprintf(outfile, "%s", "* ");
            }
            //по завершении ряда перевод строки
            fprintf(outfile, "%c", '\n');
        }
    }
    else{
        fprintf(outfile, "%s", "NO\n");
    }

    //fprintf(outfile, "%c", ' ');

    fclose(infile);
    fclose(outfile);
    return 0;
}