/*
    Проверка числа на простоту
*/
#include <stdio.h>

int num;

int main(void){

    scanf("%d", &num);

    //единица - не простое число и в дальнейшей части программы деление на неё в любом случае даст 0 в остатке, поэтому её исключаем сразу
    if(num == 1){      
        printf("NO\n");
        return 0;
    }

    for(int i = 2; i < num; i ++){
        if(num % i == 0){
            printf("NO\n");
            return 0;
        }
    }
    
    printf("YES\n");
    return 0;
}