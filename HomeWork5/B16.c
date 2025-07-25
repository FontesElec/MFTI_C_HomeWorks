#include <stdio.h>

int a, b;
int main(void){
    scanf("%d %d", &a, &b);
    while(b!= 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    //согласно алгоритму a будет содержать НОД
    printf("%d\n", a);
    return 0;
}