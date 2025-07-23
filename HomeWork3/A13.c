#include <stdio.h>


int main(void){
    int num;
    int prod = 1;
    scanf("%d" , &num);
    for(int i = 0; i < 3; i++){
        prod *= num % 10;
        num /= 10;
    }
    printf("%d\n", prod);
    return 0;
}