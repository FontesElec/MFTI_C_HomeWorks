#include <stdio.h>


int main(void){
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    if(((a + b) <= c) || ((b + c) <= a) || ((a + c) <= b)){
        printf("NO\n");
        return 0;
    }  
    printf("YES\n");
    return 0;
}