#include <stdio.h>
int num1, num2, num3;
int main(void){
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("%d+%d+%d=%d\n", num1, num2, num3, (num1 + num2 + num3));
    printf("%d*%d*%d=%d", num1, num2, num3, (num1 * num2 * num3));
    return 0;
}