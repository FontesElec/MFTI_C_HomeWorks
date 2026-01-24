/*
        На вход программе подается беззнаковое 32-битное целое число N. 
        Требуется найти количество единичных битов в двоичном представлении данного числа.
*/

#include <stdio.h>
#include <stdint.h>

#define RANGE 32

uint32_t num = 0;           //исходное число
int ones_cntr = 0;

int main(void){
    
    scanf("%d", &num);

    for(int i = 0; i < RANGE; i++){
        if((num >> i) & 1){
            ones_cntr++;
        }
    }

    printf("%d", ones_cntr);
    return 0;
}