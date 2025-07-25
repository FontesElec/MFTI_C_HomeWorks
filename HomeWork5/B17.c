#include <stdio.h>

int num;
int main(void){
    scanf("%d", &num);
    for(int i = 10; i <= num; i++){
        int sum = 0;
        int prod = 1;
        int tmp_num = i;
        while(tmp_num != 0){
            sum += tmp_num % 10;
            prod *= tmp_num % 10;
            tmp_num /= 10;
        }
        if(sum == prod){
            printf("%d ", i);
        }
    }

    return 0;
}