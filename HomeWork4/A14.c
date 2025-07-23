#include <stdio.h>


int main(void){
    int num;
    int max = 0;
    scanf("%d" , &num);
    for(int i = 0; i < 3; i++){
        if(max < num % 10){
            max = num % 10;
        }
        num /= 10;
    }
    printf("%d\n", max);
    return 0;
}