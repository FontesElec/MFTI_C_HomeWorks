#include "common.h"
#include <stdlib.h>

Screen_t* myScreen = NULL;

void food_destruction(void){
    food_t*f_ptr = myScreen->food_list;
    while(f_ptr){
        food_t* del_ptr = f_ptr;
        f_ptr = f_ptr->next_food;
        free(del_ptr);
    }
}