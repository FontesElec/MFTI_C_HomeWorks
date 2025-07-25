/*
    Проверяет, равна ли сумма цифр введённого числа 10 (REF_DIGIT)
*/
#include <stdio.h>

#define REF_DIGIT   10

int num, sum = 0;

int main(void){

    scanf("%d", &num);

    while(num != 0){
        sum += num % 10;
        num /= 10;

        //Можно проверить "на ходу", если сумма уже превысила значение, то дальше считать нет смысла, не обязательная процедура
        if(sum > REF_DIGIT){   
            printf("NO\n");
            return 0;
        }
    }

    if(sum == REF_DIGIT){
        printf("YES\n");
        return 0;
    }
    
    printf("NO\n");
    return 0;
}