#include <stdio.h>
int num1, num2, num3;
int main(void){
    scanf("%d %d %d", &num1, &num2, &num3);
    if((num1 > num2) && (num1 > num3)){
        printf("%d", num1);
        return 0;
    }
    if(num2 > num3){
        printf("%d", num2);
        return 0;
    }
    printf("%d", num3);
    return 0;
}