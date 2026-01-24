/*
        На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). 
        Требуется взять K подряд идущих битов числа N так, чтобы полученное число было максимальным. 
        Программа должна вывести полученное число.
*/

#include <stdio.h>
#include <stdint.h>

int bias = 0;               //сдвиг
uint32_t mask = 0;          //битовая маска
uint32_t num = 0;           //исходное число
uint32_t max_val = 0;       

int main(void){
    
    scanf("%d %d", &num, &bias);

    //создали маску числа
    for(int  i = bias; i > 0; i--){
        mask = (mask << 1) | 1;
    }

    //последовательно сдвигаем число вправо и накладываем маску, ища максимальное значение
    for(int i = bias; i <= 32; i++){
        uint32_t cur_val = (num >> (i - bias)) & mask;
        if(cur_val > max_val){
            max_val = cur_val;
        }
    }
    
    printf("%u", max_val);
    return 0;
}