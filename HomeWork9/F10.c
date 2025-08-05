/*
    Дана строка состоящая из маленьких латинских букв 'a'..'z'. 
    В конце строки точка. Необходимо заменить повторяющиеся буквы на <буква><количество повторений>
*/

#include <stdio.h>

#define ARR_LNG 1000

int main(void){
    char ch = 0;
    char prev_ch = 0;
    int in_cntr = 0;
    int seq_cntr = 1;
    int in[ARR_LNG] = {0};
    
    while(ch != '.'){
        scanf("%c", &ch);
        in[in_cntr] = ch;
        in_cntr++;
    }

    prev_ch = in[0];

    for(int i = 1; i < in_cntr; i++){
        if(in[i] == prev_ch){
            seq_cntr++;
        }
        else{
            printf("%c%d", prev_ch, seq_cntr);
            prev_ch = in[i];
            seq_cntr = 1;
        }
    }


    return 0;
}
