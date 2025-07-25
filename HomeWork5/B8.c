#include <stdio.h>

#define REQUIRED_NUM    9
#define REQUIRED_QTY    1

int num;
int cnt = 0;
int main(void){
    scanf("%d", &num);
    while(num != 0){
        if(num % 10 == REQUIRED_NUM){
            cnt++;
        }
        num /= 10;
    } 
    if(cnt == REQUIRED_QTY){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}