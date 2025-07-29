/*
    Дана последовательность ненулевых целых чисел, завершающаяся числом 0. Ноль в последовательность не входит. 
    Определите наибольшее значение числа в этой последовательности. Для решения задачи необходимо написать рекурсивную функцию вида:
    int max_find(int max)
*/
#include <stdio.h>
#include <limits.h>

//Прототипы функций
int max_find(int max);


int main(void){
    printf("%d", max_find(INT_MIN));
    return 0;
}

int max_find(int max){
    int num;
    scanf("%d",&num);
    if(num == 0){
        return max;
    }
    int tmp = max_find(num);
    if(tmp > max){
        return tmp;
    }
    return max;
}