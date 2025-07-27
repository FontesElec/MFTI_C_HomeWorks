/*
   Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления
*/
#include <stdio.h>

int pow_10(int pow){
    int ret = 1;
    for(int i = 0; i < pow; i++){
        ret *= 10;
    }
    return ret;
}


int main(void){
    int num, base, res = 0, pow_cnt = 0;
    scanf("%d %d", &num, &base);
    
    while (num != 0){
        res += num % base * pow_10(pow_cnt);
        pow_cnt++;
        num /= base;
    }
    
    printf("%d", res);
    return 0;
}
