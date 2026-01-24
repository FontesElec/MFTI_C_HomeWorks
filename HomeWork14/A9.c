/*
        В программе реализована структура данных:
        struct pack_array {
                uint32_t array; // поле для хранения упакованного массива из 0 и 1
                uint32_t count0 : 8; // счетчик нулей в array
                uint32_t count1 : 8; // счетчик единиц в array
        }
        Необходимо реализовать программу, которая упаковывает переданный ей массив из 32-ух элементов 0 и 1 в указанную структуру данных.
        Функция должна строго соответствовать прототипу:
        void array2struct(int [], struct pack_array *)
*/


#include <stdio.h>
#include <stdint.h>

struct pack_array {
        uint32_t array; // поле для хранения упакованного массива из 0 и 1
        uint32_t count0 : 8; // счетчик нулей в array
        uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int input[], struct pack_array * output){
    for(int i = 0; i < 32; i++){
        if(*(input + i)){
            output -> count1++;
        }
        else{
            output -> count0++;
        }
        output -> array = (output -> array << 1) | *(input + i);
    }
}


int main(void){
    struct pack_array my_pack;
    int input[32] ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < 32; i++){
        scanf("%d", input + i);
    }
    array2struct(input, &my_pack);
    printf("%u"" %d"" %d", my_pack.array, my_pack.count0, my_pack.count1);
    return 0;
}
