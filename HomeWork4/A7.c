#include <stdio.h>
int num1, num2;
int main(void){
    scanf("%d %d", &num1, &num2);
    if(num1 > num2){
        printf("%d %d", num2, num1 );
        return 0;
    }
    printf("%d %d", num1, num2 );
    return 0;
}