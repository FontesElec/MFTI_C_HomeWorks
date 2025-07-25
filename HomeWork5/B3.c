
#include <stdio.h>
int num1, num2, sum;
int main(void){
    scanf("%d %d", &num1, &num2);
    for(int i = num1; i <= num2; i++){
        sum += i * i;
    }
    printf("%d ", sum);
    return 0;
}