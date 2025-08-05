/*
    Написать функцию и программу демонстрирующую работу данной функции. Вывести в порядке возрастания цифры, 
    входящие в десятичную запись натурального числа N, не более 1000 цифр. Цифра пробел сколько раз данная цифра встречается в числе.
*/
#include <stdio.h>

#define RANGE   1000

void analyzer(char* num){
    int digs[10] = {0}; //массив для цифр от 0 до 9 будет содержать число повторений этих цифр в соответствующих индексах
    char ch = 0;
    int cntr = 0;
    while(ch != '\n'){
        ch = num[cntr];
        if((ch >= '0') && (ch <= '9')){
            digs[(int)(ch - '0')]++;
        }
        cntr++;
    }

    for(int i = 0; i < 10; i++){
        if(digs[i]){
            printf("%d %d\n", i, digs[i]);
        }
    }

}

int main(void){
    char num[RANGE + 1];
    fgets(num, RANGE + 1, stdin);
    analyzer(num);
    return 0;
}
