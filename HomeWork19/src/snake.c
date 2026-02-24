#include "snake.h"
#include <stdlib.h>
#include <ncurses/ncurses.h>

#define DISPERSION 20
#define START_SIZE 3


void init_snake(struct Snake* my_snake){
    uint8_t step = DISPERSION;
    if(my_snake->color == 0){
        my_snake->color = COLOR_WHITE;
    }
    my_snake->direction = DIR_RIGHT;
    my_snake->head_x = getmaxx(stdscr)/2 - step;
    step = - step;
    my_snake->head_y = getmaxy(stdscr)/2;
    uint16_t tmp_x = my_snake->head_x;
    Tail** t_ptr = &(my_snake->my_tail);
    for(int i = 0; i < START_SIZE; i++){ 
        *t_ptr = calloc(1, sizeof(Tail));
        t_ptr->tail_x = --tmp_x;
        t_ptr->tail_y =  my_snake->head_y;
        t_ptr = &(t_ptr->next);
    }
}
