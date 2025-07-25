#include <stdio.h>

int num;
int prev = 10;
int main(void){
    scanf("%d", &num);
    //Идём от обратного, проверим что каждая последняя цифра больше предыдущей
    while(num != 0){
        if((num % 10) >= prev){
            printf("NO\n");
            return 0;
        }
        prev = num % 10;
        num /= 10;
    }
    printf("YES\n");
    return 0;
}