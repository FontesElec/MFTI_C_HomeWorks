#include "snake.h"
#include <stdlib.h>
#include <ncurses/ncurses.h>

#define DISPERSION 20
#define START_SIZE 3

void init_snake(struct Snake* my_snake){
    static int8_t step = DISPERSION;
    if(my_snake->color == 0){
        my_snake->color = COLOR_WHITE;
    }
    my_snake->direction = DIR_RIGHT;
    my_snake->head_x = getmaxx(stdscr)/2 - step;
    step = - step;
    my_snake->head_y = getmaxy(stdscr)/2;


    uint16_t tmp_x = my_snake->head_x;
    struct Tail** t_ptr = &(my_snake->my_tail);
    struct Tail* prev_ptr = NULL;
    
    for(int i = 0; i < START_SIZE; i++){ 
        *t_ptr = calloc(1, sizeof(struct Tail));
        if(prev_ptr){
            prev_ptr->next = *t_ptr;
        }        
        (*t_ptr)->tail_x = --tmp_x;
        (*t_ptr)->tail_y =  my_snake->head_y;
        t_ptr = &((*t_ptr)->next);
        prev_ptr = *t_ptr;
    }
}

void draw_snake(struct Snake* my_snake){
    //Задаём цвет
    attron(COLOR_PAIR(my_snake->color));

    //Рисуем голову
    mvprintw(my_snake->head_y, my_snake->head_x, "e");

    //Рисуем хвост
    struct Tail* t_ptr = my_snake->my_tail;
    while (t_ptr){
        mvprintw(t_ptr->tail_y, t_ptr->tail_x, "*");
        t_ptr = t_ptr->next;
    }
    attroff(COLOR_PAIR(my_snake->color));
    refresh();    
}

static void coords_moving_up(uint16_t* x_addr, uint16_t* y_addr){
    (void)x_addr;
    (*y_addr)--;
}

static void coords_moving_down(uint16_t* x_addr, uint16_t* y_addr){
    (void)x_addr;
    (*y_addr)--;
}

static void coords_moving_left(uint16_t* x_addr, uint16_t* y_addr){
    (void)y_addr;
    (*x_addr)--;
}

static void coords_moving_right(uint16_t* x_addr, uint16_t* y_addr){
    (void)y_addr;
    (*x_addr)++;
}

void move_snake(struct Snake* my_snake){
    uint16_t x_prev = my_snake->head_x, y_prev = my_snake->head_y;

    //Поворот головы
    switch(my_snake->direction){
        case DIR_UP:    coords_moving_up(&(my_snake->head_x), &(my_snake->head_y)); break;
        case DIR_DOWN:  coords_moving_down(&(my_snake->head_x), &(my_snake->head_y)); break;
        case DIR_LEFT:  coords_moving_left(&(my_snake->head_x), &(my_snake->head_y)); break;
        case DIR_RIGHT: coords_moving_right(&(my_snake->head_x), &(my_snake->head_y)); break;
    }
    
    struct Tail* t_ptr = my_snake->my_tail;

    while(t_ptr){
        uint16_t x_cur = t_ptr->tail_x, y_cur = t_ptr->tail_y;
        t_ptr->tail_x = x_prev;
        t_ptr->tail_y = y_prev;
        if(t_ptr->next){
            x_prev = x_cur;
            y_prev = y_cur;
        }
        t_ptr = t_ptr -> next;
    }

}
