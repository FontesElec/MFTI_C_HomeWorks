#include <stdio.h>
int num1, num2, num3;
int main(void){
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("%.2f",(num1 + num2 + num3) / 3.0f);
    return 0;
}