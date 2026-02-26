#include "game.h"
#include "snake.h"
#include "common.h"
#include <time.h>
#include <ncurses/ncurses.h>

extern Screen_t* myScreen;
static uint8_t final = 0;

//Custom delay instead timeout and usleep functions
static void c_delay_ms(double delay){
    clock_t begin = clock();
    while((double)(clock() - begin) < delay){};
}

//Инициализация всех змеек
static void all_snakes_init(void){
    uint8_t snake_num = 1;
    struct Snake* s_ptr = myScreen->snake_list;
    while(s_ptr){
        init_snake(s_ptr, snake_num);
        s_ptr = s_ptr->next;
        if(myScreen->snakes >= snake_num){
            snake_num++;
        }
    }
}

//Движение
static void all_snakes_moving(void){
    struct Snake* s_ptr = myScreen->snake_list;
    while(s_ptr){
        move_snake(s_ptr);
        s_ptr = s_ptr->next;
    }
}

//Проверка на наличия заданной клавиши в списке управления змейкой
direction_t is_my_direction(int key, struct Snake* my_snake){
    const keys_t* key_ptr = my_snake->controll_keys;
    while((key_ptr->key) != 0){
        if(key == key_ptr->key){
            return key_ptr->direction;
        }
        key_ptr++;
    }
    return NO_DIR;
}

//Проверка на допустимость изменения движения
static uint8_t is_opposite_direction(direction_t my_dir, direction_t new_dir){
    switch(my_dir){
        case DIR_UP:    if(new_dir == DIR_DOWN)  return 1; break;
        case DIR_DOWN:  if(new_dir == DIR_UP)    return 1; break;
        case DIR_LEFT:  if(new_dir == DIR_RIGHT) return 1; break;
        case DIR_RIGHT: if(new_dir == DIR_LEFT)  return 1; break;
        case NO_DIR: return 0; break;
        default: return 0;
    }
    return 0;
}

//Смена направления
static void change_direction(int key){
    struct Snake* s_ptr = myScreen->snake_list;
    uint8_t num_of_snake = 1;
    while((s_ptr) && (num_of_snake <= myScreen->snakes)){
        direction_t new_dir =  is_my_direction(key, s_ptr);
        if((new_dir != NO_DIR) && (!is_opposite_direction(s_ptr->direction, new_dir))){
            s_ptr->direction = new_dir;
            return;
        }
        num_of_snake++;
        s_ptr = s_ptr->next;
    }
}


//Проверка на столкновения
static void check_self_collisions(){
    struct Snake* s_ptr = myScreen->snake_list;
    while(s_ptr){
        snake_self_collision(s_ptr);
        s_ptr = s_ptr->next;
    }
}



activity_t game_page(void){
    clear();
    nodelay(stdscr, TRUE);
    all_snakes_init();
    int ch = 0;

    while(!final){
        
        all_snakes_moving();
        check_self_collisions();
        ch = getch();

        switch (ch){
            case 0: break;
            case EXIT_KEY: return FINAL;
            case 'q': case 'Q': case 1081: case 1049: return GAME_OVER;
            default: change_direction(ch);
        }
        ch = 0;
        c_delay_ms(200 / myScreen->speed);
    }
    return GAME_OVER;
}

