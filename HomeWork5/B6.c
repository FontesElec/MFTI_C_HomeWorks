#include <stdio.h>
int num, prev, cur;
int main(void){
    prev = 10;  //такое число никогда не случится при получении остатка деления на 10
    scanf("%d", &num);
    while(num != 0){
         cur = num % 10;
        if(prev == cur){
            printf("YES\n");
            return 0;
        }
        prev = cur;
        num /= 10;
    }
    printf("NO\n");
    return 0;
}