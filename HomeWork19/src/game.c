#include "game.h"
#include "snake.h"
#include "common.h"
#include <time.h>
#include <ncurses/ncurses.h>
#include <stdlib.h>


#define FOOD_NUMS     3
#define POINTS_TO_WIN 20

const char food_symbol[] = "*";

extern Screen_t* myScreen;

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

//Раскидывание еды
static void food_spaming(void){
    food_t** addr_f_ptr = &(myScreen->food_list);
    food_t** prev_addr_f_ptr = NULL;
    for(int i = 0; i < FOOD_NUMS; i++){
        *addr_f_ptr =  calloc(1, sizeof(food_t));
        if(prev_addr_f_ptr){
            (*prev_addr_f_ptr)->next_food =  *addr_f_ptr;
        }
        (*addr_f_ptr)->food_x = rand() % (getmaxx(stdscr) - RIGHT_BORDER);
        (*addr_f_ptr)->food_y = rand() % (getmaxy(stdscr) - LOWER_BORDER);
        mvprintw((*addr_f_ptr)->food_y,  (*addr_f_ptr)->food_x, food_symbol);
        prev_addr_f_ptr = addr_f_ptr;
        addr_f_ptr = &((*addr_f_ptr)->next_food);
    }
    refresh();
}

//Уничтожение еды
static void food_destrying(food_t* del_f_ptr){
    food_t* f_ptr = myScreen->food_list;
    food_t* prev_food = NULL;
    while(f_ptr){
        if(f_ptr == del_f_ptr){
            //если это первый элемент в списке
            if(!prev_food){
                myScreen->food_list = del_f_ptr->next_food;
                free(del_f_ptr);
            }
            //если удаляем из середины или хвоста
            else{
                prev_food->next_food = del_f_ptr->next_food;
                free(del_f_ptr);
            }
            return;
        }
        prev_food = f_ptr;
        f_ptr = f_ptr->next_food;
    }
    refresh();
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

static uint8_t check_self_collisions(){
    uint8_t collisions = 0;
    struct Snake* s_ptr = myScreen->snake_list;
    while(s_ptr){
        collisions = collisions | snake_self_collision(s_ptr);
        s_ptr = s_ptr->next;
    }
    return collisions;
}

static uint8_t was_food_eaten(void){
    food_t* f_ptr = myScreen->food_list;
    struct Snake* s_ptr = myScreen->snake_list;
    uint8_t at_least_one_eaten = 0;
    while(f_ptr){
        uint8_t was_eaten = 0;
        while(s_ptr){
            if((s_ptr->head_x == f_ptr->food_x) && (s_ptr->head_y == f_ptr->food_y)){
                grow_snake(s_ptr);
                was_eaten = 1;
            }
            s_ptr = s_ptr->next;
        }
        if(was_eaten){
            at_least_one_eaten = 1;
            food_t* del_f_ptr = f_ptr;
            f_ptr = f_ptr->next_food;
            food_destrying(del_f_ptr);
        }
        else{
            f_ptr = f_ptr->next_food;
        }
        s_ptr = myScreen->snake_list;
    }
    return at_least_one_eaten;
}

//Проверка на столкновения
static uint8_t check_collisions(void){
    uint8_t collisions = 0;
    collisions = collisions  | check_self_collisions();
    collisions = collisions  | snake_vs_snake_collision(myScreen->snake_list, myScreen->snake_list->next);
    collisions = collisions  | snake_vs_snake_collision(myScreen->snake_list->next, myScreen->snake_list); 
    collisions = collisions  | was_food_eaten();
    return collisions;
}

//Отрисовка поля очков
static void points_drawing(void){
    uint16_t y = 1, x = getmaxx(stdscr) - RIGHT_BORDER + 3, cntr = 1;;
    mvvline(0, getmaxx(stdscr) - RIGHT_BORDER + 1, '|', getmaxy(stdscr));
    mvprintw(y,  x, "SCORES:");
    struct Snake* s_ptr = myScreen->snake_list;
    y +=2;
    while(s_ptr){
        mvprintw(y, x, "Snake %d:        ", cntr); //Затирает предыдущее значение
        mvprintw(y, x, "Snake %d:  %d", cntr ,s_ptr->points);
        y++;
        cntr++;
        s_ptr = s_ptr->next;
    }

}

//Отрисовка подсказки по меню
static void hints_drawing(void){
    mvhline(getmaxy(stdscr) - LOWER_BORDER + 1, 0,'_', getmaxx(stdscr));
    mvprintw(getmaxy(stdscr) - LOWER_BORDER + 2, 1, "Use arrows or 'WASD' nj contol snakes, press 'Q' to finish game, press 'F10' to exit game");
}


activity_t game_page(void){
    clear();
    nodelay(stdscr, TRUE);
    all_snakes_init();
    hints_drawing();
    points_drawing();
    food_spaming();
    
    int ch = 0;

    while(1){ 
        all_snakes_moving();
        struct Snake* s_ptr = myScreen->snake_list;
        if(check_collisions()){
            //Игра заканчивается, когда очки падают до нуля
            while(s_ptr){
                if((s_ptr->points == 0) || (s_ptr->points >= POINTS_TO_WIN)){
                    return GAME_OVER;
                }
                s_ptr = s_ptr->next;
            }
            points_drawing();
            //Обновляем еду если закончилась
            if(myScreen->food_list == NULL){
                food_spaming();
            }            
        }
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

