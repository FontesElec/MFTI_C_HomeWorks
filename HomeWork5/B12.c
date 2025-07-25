#include <stdio.h>
#include <limits.h>

int num;
int min = INT_MAX;
int max = INT_MIN;
int main(void){
    scanf("%d", &num);
    do{
        if(num % 10 > max){
            max = num % 10;
        }
        if(num % 10 < min){
            min = num % 10;
        }
        num /= 10;
    }while(num != 0);
    printf("%d %d\n", min, max);
    return 0;
}