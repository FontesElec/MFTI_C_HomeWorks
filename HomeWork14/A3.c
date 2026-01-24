/*
        На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). 
        Требуется взять K младших битов числа N и вывести полученное таким образом число.
*/

#include <stdio.h>
#include <stdint.h>

int bias = 0;               //сдвиг
uint32_t mask = 0;          //битовая маска
uint32_t num = 0;           //исходное число

int main(void){
    
    scanf("%d %d", &num, &bias);
    
    for(int  i = bias; i > 0; i--){
        mask = (mask << 1) | 1;
    }
    
    printf("%u", num & mask);
    return 0;
}