/*
    Необходимо вычислить выражение написанное в обратной польской записи. 
    На вход подается строка состоящая из целых, неотрицательных чисел и арифметических символов. 
    В ответ единственное целое число - результат.
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define ARR_LNG 1000

typedef struct stack_obj_t{
    int64_t val;
    struct stack_obj_t* next;
}stack_obj_t;

stack_obj_t* push(stack_obj_t* top, int64_t val){
    stack_obj_t* ptr = calloc(1, sizeof(stack_obj_t));
    ptr -> val = val;
    ptr -> next = top;
    return ptr;
}

stack_obj_t* pop(stack_obj_t* top){
    if(!top){
        return NULL;
    }
    stack_obj_t* next_ptr = top -> next;
    free(top);
    return next_ptr;
}

int main(void){
    //100 25 + 25 /.
    //8 2 5 * + 1 3 2 * + 4 - /.

    stack_obj_t* top = NULL;
    char ch = 0;
    int64_t num = 0;

    while(ch != '.'){
        ch = getchar();
        while((ch >= '0') && (ch <= '9')){
           num = num * 10 + (int64_t)(ch - '0');
           ch = getchar();
        }
        switch (ch){
            case ' ': { 
                top = push(top, num); 
                num = 0;
                break;
            }
            case '+' : {
                top -> next -> val = top -> next -> val + top -> val;
                top = pop(top);
                ch = getchar();
                break;
            }
            case '-' : {
                top -> next -> val = top -> next -> val - top -> val;
                top = pop(top);
                ch = getchar();
                break;
            }
            case '*' : {
                top -> next -> val = top -> next -> val * top -> val;
                top = pop(top);
                ch = getchar();
                break;
            }
            case '/' : {
                top -> next -> val = top -> next -> val / top -> val;
                top = pop(top);
                ch = getchar();
                break;
            }
            
        }

    }

    printf("%ld", top -> val);

    while(top){
        top = pop(top);
    }
    
    return 0;
}