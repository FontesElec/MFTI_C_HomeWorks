#include <stdio.h>


int main(void){
    int month;
    scanf("%d", &month);
    if((month > 0) && (month <= 2) || (month == 12)){
        printf("winter\n");
        return 0;
    }
    if((month > 2) && (month <= 5)){
        printf("spring\n");
        return 0;
    }
    if((month > 5) && (month <= 8)){
        printf("summer\n");
        return 0;
    }
    if((month > 8) && (month <= 11)){
        printf("autumn\n");
        return 0;
    }
    return 0;
}