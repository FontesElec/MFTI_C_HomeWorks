#include <stdio.h>

int num;
int inv = 0;
int main(void){
    scanf("%d", &num);
    do{
        inv = inv * 10 + num % 10;
        num /= 10;
    }while(num != 0);
    printf("%d\n", inv);
    return 0;
}