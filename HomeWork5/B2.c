
#include <stdio.h>
int num1, num2;
int main(void){
    scanf("%d %d", &num1, &num2);
    for(int i = num1; i <= num2; i++){
        printf("%d ", i * i);
    }
    return 0;
}