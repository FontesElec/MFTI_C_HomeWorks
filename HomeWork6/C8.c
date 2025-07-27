/*
    Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее использования
*/
#include <stdio.h>


//Прототипы функций
unsigned char conv_to_caps(unsigned char ch);

//Переменные
char STEP = 'a' - 'A';  //строчные буквы в ASCII отстают от своих заглавных но определённый шаг

int main(void){
    unsigned char ch;
    while(1){
        scanf("%c", &ch);
        if(ch == '.'){
            return 0;
        }
        printf("%c", conv_to_caps(ch));

    }
    
    return 0;
}

unsigned char conv_to_caps(unsigned char ch){
    /*
        Проверяем, относится ли символ к диапазону строчных букв
        Начинается диапазон с 'a' (0d97) и заканчивается 'z' (0d122)
        Чтобы не проводить проверку на равенство, "расширим" границы диапазона на 1 с обеих сторон
    */
    if((ch > (unsigned char)96) && (ch < (unsigned char)123)){
        ch -= STEP;
    }

    return ch;
}