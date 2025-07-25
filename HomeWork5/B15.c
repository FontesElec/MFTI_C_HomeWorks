#include <stdio.h>

int num = 10;           //произвольное ненулевое число
int even_cntr = -1;     //-1 чтобы не учитывать ноль как чётное
int main(void){
    while(num != 0){
        scanf("%d", &num);
        if(num % 2 == 0){
            even_cntr++;
        }
    }
    printf("%d\n", even_cntr);
    return 0;
}