/*
        На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). 
        Требуется циклически сдвинуть биты числа N вправо на K битов и вывести полученное таким образом число.
*/

#include <stdio.h>
#include <stdint.h>

int bias = 0;               //сдвиг
int last_digit = 0;         //цифра, которую следует перенести в начало
uint32_t num = 0;           //исходное число


int main(void){
    
    scanf("%d %d", &num, &bias);
    for(int  i = bias; i > 0; i--){
        last_digit = num & 1;
        num >>= 1;
        num = num | ((uint32_t)last_digit << 31);
    }
    
    printf("%u", num);
    return 0;
}