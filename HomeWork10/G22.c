/*
    Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи ли два английских слова по звучанию. 
    На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код. Если коды двух слов совпадают, 
    то слова, как правило, звучат похоже.

    Вам требуется реализовать этот алгоритм. Он работает так:

    Первая буква слова сохраняется.
    В остальной части слова:
    буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются; 
    оставшиеся буквы (согласные) заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
        1: b, f, p, v
        2: c, g, j, k, q, s, x, z
        3: d, t
        4: l
        5: m, n
        6: r
    Любая последовательность одинаковых цифр сокращается до одной такой цифры. Итоговая строка обрезается до первых четырёх символов. 
    Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.
    
    Примеры:
        аmmonium → ammnm → a5555 → a5 → a500
        implementation → implmnttn → i51455335 → i514535 → i514
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *infile;
FILE *outfile;

#define STR_LNG 21

int main(void){
    
    char str[STR_LNG] = {'0'};
    

    infile = fopen("input.txt", "r");
    outfile = fopen("output.txt", "w");

    //fscanf(infile, "%s", str);
    //fgets(str, STR_LNG, infile);

    fscanf(infile, "%s", str);
    
    //Проходим по строке и стираем все гласные и заменяем согласные согласно списку
    for(int i = 1; i < STR_LNG; i++){
        switch(str[i]){
            //a, e, h, i, o, u, w и y — отбрасываются
            case 'a':
            case 'e':
            case 'h':
            case 'i':
            case 'o':
            case 'u':
            case 'w':
            case 'y': str[i] = '0';
            break;
            
            //1: b, f, p, v
            case 'b':
            case 'f':
            case 'p':
            case 'v': str[i] = '1';
            break;

            //2: c, g, j, k, q, s, x, z
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z': str[i] = '2';
            break;

            //3: d, t
            case 'd':
            case 't': str[i] = '3';
            break;

            //4: l
            case 'l': str[i] = '4';
            break;

            //5: m, n
            case 'm':
            case 'n': str[i] = '5';
            break;
            
            //6: r
            case 'r': str[i] = '6';
            break;

            default: str[i] = '0';
        }
    }

    //проводим процесс уничтожения повторяющихся символов
    char* prev_char_ptr = str;
    for(int i = 1; i < STR_LNG; i++){
        if(str[i] != '0'){                          //если есть символ (не '0'), то сравниваем с предыдущим
            if(str[i] == *prev_char_ptr){           //если совпадают
                str[i] = '0';                       //то "обнуляем" значение
            }
            else{                                   //если не совпадают
                prev_char_ptr = str + i;            //то пишем новый адрес значения
            }
        }
    }

    //переносим в начало все значащие символы
    for(int i = 1; i < STR_LNG; i++){
        if(str[i] != '0'){
            int j = 0;
            //ищем первое свободное место
            while((str[j] != '0') && (j < STR_LNG)){
                j++;
            }
            //если пустое место раньше чем символ
            if(j < i){
                //вписываем в свободное место свой символ
                str[j] = str[i];
                //стираем символ из изначальной позиции
                str[i] = '0';
            }
        }
    }

    //обрезаем до первых четырёх символов
    for(int i = 0; i < 4; i++){
        fprintf(outfile, "%c", str[i]);
    }

    //fprintf(outfile, "%c", ' ');

    fclose(infile);
    fclose(outfile);
    return 0;
}