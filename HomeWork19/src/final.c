#include <ncurses/ncurses.h>
#include <stdlib.h>
#include "snake.h"
#include "final.h"

extern Screen_t* myScreen;

activity_t screen_destruction(void){
    food_destruction();
    struct Snake* s_ptr = myScreen->snake_list;
    while(s_ptr){
        struct Snake* del_ptr = s_ptr;
        s_ptr = s_ptr->next;
        snake_destruction(del_ptr);
    }
    endwin();
    return EXIT;
}