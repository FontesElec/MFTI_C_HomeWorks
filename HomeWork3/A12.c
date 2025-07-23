#include <stdio.h>


int main(void){
    int num;
    int sum = 0;
    scanf("%d" , &num);
    for(int i = 0; i < 3; i++){
        sum += num % 10;
        num /= 10;
    }
    printf("%d\n", sum);
    return 0;
}