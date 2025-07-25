
#include <stdio.h>
int num;
int main(void){
    scanf("%d", &num);
    if ((num < 1000) && (num > 99)){
        printf("YES\n");\
        return 0;
    }
    printf("NO\n");
    return 0;
}