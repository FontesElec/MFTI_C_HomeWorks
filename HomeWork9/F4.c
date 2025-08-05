/*
    Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры, входящие в строку. 
    Цифра - количество. Функция должно строго соответствовать прототипу: void print_digit(char s[])
*/
#include <stdio.h>

void print_digit(char s[]){
    int digs[10] = {0}; //массив для цифр от 0 до 9 будет содержать число повторений этих цифр в соответствующих индексах
    int cntr = 0;
    char ch = 0;
    while(ch != '.'){
        ch = s[cntr];
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
    char str[] = {"Hello123 world77."};
    print_digit(str);
    return 0;
}
