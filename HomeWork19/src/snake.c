#include "snake.h"
#include <stdlib.h>
#include <ncurses/ncurses.h>

#define DISPERSION 20
#define START_SIZE 3

//Задаём клавиши контроля направления змеек
const keys_t key_list_1[] = {{UP_KEY, DIR_UP}, {DOWN_KEY, DIR_DOWN},{RIGHT_KEY, DIR_RIGHT}, {LEFT_KEY, DIR_LEFT}, {0, 0}};
const keys_t key_list_2[] = {{(int)'w', DIR_UP},   {(int)'W', DIR_UP},   {1094, DIR_UP},   {1062, DIR_UP},
                      {(int)'a', DIR_LEFT}, {(int)'A', DIR_LEFT}, {1092, DIR_LEFT}, {1060, DIR_LEFT},
                      {(int)'d', DIR_RIGHT},{(int)'D', DIR_RIGHT},{1074, DIR_RIGHT},{1042, DIR_RIGHT},
                      {(int)'s', DIR_DOWN}, {(int)'S', DIR_DOWN}, {1099, DIR_DOWN}, {1067, DIR_DOWN}, {0,0}};

char head_symbol = 'o';
char tail_symbol = 'x';

void init_snake(struct Snake* my_snake, uint8_t snake_num){
    static int8_t step = DISPERSION;

    //Стартовые настройки змеи
    if(my_snake->color == 0){
        my_snake->color = COLOR_WHITE;
    }
    my_snake->direction = DIR_RIGHT;
    my_snake->head_x = getmaxx(stdscr)/2 - step;
    step = - step;
    my_snake->head_y = getmaxy(stdscr)/2;
    switch (snake_num){
        case 1: my_snake->controll_keys = key_list_1; break;
        case 2: my_snake->controll_keys = key_list_2; break;
        default: break;
    }
    my_snake->head_symbol = head_symbol;
    my_snake->tail_symbol = tail_symbol;

    //Инициализация хвоста
    uint16_t tmp_x = my_snake->head_x;  //так как базово змея движется вправо, то координаты хвоста будут меняться по x
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

    //Задаём цвет
    attron(COLOR_PAIR(my_snake->color));

    //Рисуем голову
    mvprintw(my_snake->head_y, my_snake->head_x, my_snake->head_symbol);

    //Рисуем хвост
    struct Tail* t_ptr = my_snake->my_tail;
    while (t_ptr){
        mvprintw(t_ptr->tail_y, t_ptr->tail_x, my_snake->head_symbol);
        t_ptr = t_ptr->next;
    }
    attroff(COLOR_PAIR(my_snake->color));
    refresh();
}

static void coords_moving_up(uint16_t* x_addr, uint16_t* y_addr){
    (void)x_addr;
    //Защита от выхода за пределы экрана
    if((*y_addr) == 0){
        (*y_addr) = getmaxy(stdscr);
        return;
    }
    (*y_addr)--;
}

static void coords_moving_down(uint16_t* x_addr, uint16_t* y_addr){
    (void)x_addr;
    //Защита от выхода за пределы экрана
    if((*y_addr) == getmaxy(stdscr)){
        (*y_addr) = 0;
        return;
    }
    (*y_addr)++;
}

static void coords_moving_left(uint16_t* x_addr, uint16_t* y_addr){
    (void)y_addr;
    //Защита от выхода за пределы экрана
    if((*x_addr == 0)){
        (*x_addr) = getmaxx(stdscr);
        return;
    }
    (*x_addr)--;
}

static void coords_moving_right(uint16_t* x_addr, uint16_t* y_addr){
    (void)y_addr;
    //Защита от выхода за пределы экрана
    if((*x_addr) == getmaxx(stdscr)){
        (*x_addr) = 0;
        return;
    }
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

    //Отрисовка головы
    attron(COLOR_PAIR(my_snake->color));
    mvprintw(my_snake->head_y, my_snake->head_x, my_snake->head_symbol);

    //Отрисовка первого звена хвоста взамен головы
    mvprintw(y_prev, x_prev, my_snake->tail_symbol);
    
    struct Tail* t_ptr = my_snake->my_tail;

    while(t_ptr){
        uint16_t x_cur = t_ptr->tail_x, y_cur = t_ptr->tail_y;
        //Затираем последнее звено
        if(!(t_ptr->next)){
            mvprintw(t_ptr->tail_y, t_ptr->tail_x, " ");
        }
        t_ptr->tail_x = x_prev;
        t_ptr->tail_y = y_prev;
        if(t_ptr->next){
            x_prev = x_cur;
            y_prev = y_cur;
        }
        t_ptr = t_ptr -> next;
    }

    attroff(COLOR_PAIR(my_snake->color));
}
