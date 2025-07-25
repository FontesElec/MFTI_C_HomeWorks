#include <stdio.h>
int num, sum;
int main(void){
    sum = 0;
    scanf("%d", &num);
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    printf("%d\n", sum);
    return 0;
}