#include <stdio.h>


int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    if(num1 > num2){
        printf("Above\n");
        return 0;
    }
    if(num1 < num2){
        printf("Less\n");
        return 0;
    }
    printf("Equal\n");
    return 0;
}