#include <stdio.h>

int num = 10;           //произвольное ненулевое число
int nums_cntr = -1;     //чтобы не учитывать финальный ноль
int main(void){
    while(num != 0){
        scanf("%d", &num);
        nums_cntr++;
    }
    printf("%d\n", nums_cntr);
    return 0;
}