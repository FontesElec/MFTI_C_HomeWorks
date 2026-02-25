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

//Инициализация всех змеек
static void all_snakes_init(void){
    struct Snake* s_ptr = myScreen->snake_list;
    while(s_ptr){
        init_snake(s_ptr);
        s_ptr = s_ptr->next;
    }
}

//Отрисовка всех змеек
static void all_snake_drawing(void){
    struct Snake* s_ptr = myScreen->snake_list;
    while(s_ptr){
        draw_snake(s_ptr);
        s_ptr = s_ptr->next;
    }
}

//Движение
static void all_snake_moving(void){
    struct Snake* s_ptr = myScreen->snake_list;
    while(s_ptr){
        move_snake(s_ptr);
        s_ptr = s_ptr->next;
    }
}


activity_t game_page(void){
    clear();
    all_snakes_init();
    all_snake_drawing();

    while(1){
        clear();
        all_snake_moving();
        all_snake_drawing();
        refresh();
        c_delay_ms(500);
    }
    return GAME_OVER;
}

