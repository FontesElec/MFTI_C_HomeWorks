#include <stdio.h>

int num;
int even_cntr = 0;
int odd_cntr = 0;
int main(void){
    scanf("%d", &num);
    do{
        if((num % 10) % 2 == 0){
           even_cntr++;
        }
        else{
            odd_cntr++;
        }
        
        num /= 10;
    }while(num != 0);
    printf("%d %d\n", even_cntr, odd_cntr);
    return 0;
}