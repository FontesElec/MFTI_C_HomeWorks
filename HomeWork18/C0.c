/*
    Сколько различных трехзначных чисел можно получить из заданного натурального N, 
    вычеркивая цифры из его десятичной записи?
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ARR_LNG 200

int main(void){
    char inp[ARR_LNG] = {'\0'};
    int count = 0;
    int cap = 0;

    scanf("%s", inp);
    
    while(inp[cap] != '\0'){
        cap++;
    }

    if(cap < 3){
        printf("%d", 0);
        return 0;
    }

    count = 0;
    int unique[1000] = {0};   // для отметки уже найденных чисел

    // выбираем 3 разных индекса i < j < k
    for (int i = 0; i < cap - 2; i++) {
        for (int j = i + 1; j < cap - 1; j++) {
            for (int k = j + 1; k < cap; k++) {
                
                int number = (inp[i] - '0') * 100 +
                             (inp[j] - '0') * 10 +
                             (inp[k] - '0');

                if (!unique[number] && number > 99) {
                    unique[number] = 1;
                    count++;
                }
            }
        }
    }
    printf("%d", count);
}