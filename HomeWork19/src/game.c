#include "game.h"
#include "snake.h"
#include "common.h"
#include <time.h>
#include <ncurses/ncurses.h>



extern Screen_t* myScreen;

//Custom delay instead timeout and usleep functions
static void c_delay_ms(double delay){
    clock_t begin = clock();
    while((double)(clock() - begin) < delay){};
}


activity_t game_page(void){

    struct Snake* s_ptr = my_screen->snake_list;
    while(s_ptr){
        init_snake(s_ptr);
        s_ptr = s_ptr->next;
    }

    return GAME_OVER;
}

