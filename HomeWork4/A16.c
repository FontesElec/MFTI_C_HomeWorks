#include <stdio.h>


int main(void){
   int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);
    if((num1 < num2) && (num2 < num3)){
         printf("YES\n");
         return 0;
    }
    printf("NO\n");
    return 0;
}