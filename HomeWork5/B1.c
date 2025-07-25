#include <stdio.h>
int num;
int main(void){
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        printf("%d %d %d\n", i, i * i, i * i * i);
    }
    return 0;
}