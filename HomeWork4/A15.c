#include <stdio.h>


int main(void){
    float x1, x2, y1,y2;
    float k, b;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    k =(y2 - y1) /  (x2 -x1) ;
    b = y1 - k * x1;
    printf("%.2f %.2f\n", k, b);
    return 0;
}