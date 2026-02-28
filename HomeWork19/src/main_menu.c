#include "main_menu.h"
#include <stdlib.h>
#include "snake.h"

extern Screen_t* myScreen;
static uint8_t ready_flg = 0;

static void ready_to_play(uint8_t param){
    //Пропускаем параметр, приходится подобное делать для унификации функции 
    (void)param;
    ready_flg = 1;
}

static void set_speed(uint8_t param){
    if(myScreen){
        myScreen -> speed = param;
    }
}

static void set_snakes(uint8_t param){
    if(myScreen){
        myScreen -> snakes = param;
    }
}

static void s1_set_color(uint8_t param){
    if(myScreen){
        if(myScreen->snake_list){
            myScreen -> snake_list -> color = param;
        }
        else{
            myScreen -> snake_list =  calloc(1, sizeof(struct Snake));
            myScreen -> snake_list -> color = param;
        }
    }
}
static void s2_set_color(uint8_t param){
    if(myScreen){
        if(!myScreen->snake_list){
            myScreen -> snake_list =  calloc(1, sizeof(struct Snake));
            myScreen -> snake_list -> color = 0;
        }
        if(myScreen->snake_list && myScreen->snake_list->next){
            myScreen -> snake_list -> next -> color = param; 
        }
        else{
            myScreen -> snake_list -> next = calloc(1, sizeof(struct Snake));
            myScreen -> snake_list -> next -> color = param;
        }
    }   
}

static void show_config(void){
    mvvline(1, 74, '|', 8);
    mvprintw(1,  76, "SELECTED CONFIGURATION:");
    mvprintw(3,  76, "SPEED:  %d", myScreen->speed);
    mvprintw(4,  76, "SNAKES: %d", myScreen->snakes);
    if(myScreen->snake_list){
        mvprintw(5, 76, "SNAKE 1 COLOR: %d", myScreen->snake_list->color);
    }
    if(myScreen->snake_list && myScreen->snake_list->next){
        mvprintw(6, 76, "SNAKE 2 COLOR: %d", myScreen->snake_list->next->color);
    }     
    refresh();
}

activity_t main_menu_page(){

    clear();

//----------------------------------------------TYPES----------------------------------------------    
    typedef enum{
        NORMAL,
        BOLD,
        COLORED,
    }style_t;

    struct __attribute__((packed)) menu_obj{
        char* text;
        uint16_t x;
        uint16_t y;
        style_t style;
        uint8_t parameter;
        struct menu_obj* right_id;
        struct menu_obj* left_id;
        struct menu_obj* upper_id;
        struct menu_obj* lower_id;
        struct menu_obj* next_id;
        void(*action)(uint8_t p);
    };
//==================================================================================================================

//------------------------------------------------MENU OBJ INITIALISATION-------------------------------------------
    //MENU OBJECT LIST
    struct menu_obj menu_sign;
    struct menu_obj speed_sign;
    struct menu_obj speed_1;
    struct menu_obj speed_2;
    struct menu_obj speed_3;
    struct menu_obj speed_4;
    struct menu_obj snakes_sign;
    struct menu_obj snake_1;
    struct menu_obj snake_2;
    struct menu_obj snake_1_color;
    struct menu_obj snake_1_red;
    struct menu_obj snake_1_green;
    struct menu_obj snake_1_yellow;
    struct menu_obj snake_1_blue;
    struct menu_obj snake_1_mag;
    struct menu_obj snake_1_cyan;
    struct menu_obj snake_1_white;
    struct menu_obj snake_2_color;
    struct menu_obj snake_2_red;
    struct menu_obj snake_2_green;
    struct menu_obj snake_2_yellow;
    struct menu_obj snake_2_blue;
    struct menu_obj snake_2_mag;
    struct menu_obj snake_2_cyan;
    struct menu_obj snake_2_white;
    struct menu_obj start_sign;

//  NAME                              .text               .x  .y .style   .param          .right_id       .left_id        .upper_id       .lover_id       .next_id          .activity  
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    menu_sign =     (struct menu_obj){"MAIN MENU",         1,  1, BOLD,    0,             NULL,           NULL,           NULL,           NULL,           &speed_sign,      NULL};
    speed_sign =    (struct menu_obj){"Speed:",            1,  3, BOLD,    0,             NULL,           NULL,           NULL,           NULL,           &speed_1,         NULL};
    speed_1 =       (struct menu_obj){"1",                 9,  3, BOLD,    1,             &speed_2,       &speed_4,       &start_sign,    &snake_1,       &speed_2,         set_speed};
    speed_2 =       (struct menu_obj){"2",                 13, 3, NORMAL,  2,             &speed_3,       &speed_1,       &start_sign,    &snake_1,       &speed_3,         set_speed};
    speed_3 =       (struct menu_obj){"3",                 17, 3, NORMAL,  3,             &speed_4,       &speed_2,       &start_sign,    &snake_1,       &speed_4,         set_speed};
    speed_4 =       (struct menu_obj){"4",                 21, 3, NORMAL,  4,             &speed_1,       &speed_3,       &start_sign,    &snake_1,       &snakes_sign,     set_speed};
    snakes_sign =   (struct menu_obj){"Snakes:",           1,  4, BOLD,    0,             NULL,           NULL,           NULL,           NULL,           &snake_1,         NULL};
    snake_1 =       (struct menu_obj){"1",                 9,  4, NORMAL,  1,             &snake_2,       &snake_2,       &speed_1,       &snake_1_red,   &snake_2,         set_snakes};
    snake_2 =       (struct menu_obj){"2",                 13, 4, NORMAL,  2,             &snake_1,       &snake_1,       &speed_1,       &snake_1_red,   &snake_1_color,   set_snakes};
    snake_1_color = (struct menu_obj){"1st snake color:",  1,  5, BOLD,    0,             NULL,           NULL,           NULL,           NULL,           &snake_1_red,     NULL};
    snake_1_red =   (struct menu_obj){"RED",               19, 5, COLORED, COLOR_RED,     &snake_1_green, &snake_1_white, &snake_1,       &snake_2_red,   &snake_1_green,   s1_set_color};
    snake_1_green = (struct menu_obj){"GREEN",             25, 5, COLORED, COLOR_GREEN,   &snake_1_yellow,&snake_1_red,   &snake_1,       &snake_2_red,   &snake_1_yellow,  s1_set_color};
    snake_1_yellow =(struct menu_obj){"YELLOW",            33, 5, COLORED, COLOR_YELLOW,  &snake_1_blue,  &snake_1_green, &snake_1,       &snake_2_red,   &snake_1_blue,    s1_set_color};
    snake_1_blue =  (struct menu_obj){"BLUE",              42, 5, COLORED, COLOR_BLUE,    &snake_1_mag,   &snake_1_yellow,&snake_1,       &snake_2_red,   &snake_1_mag,     s1_set_color};
    snake_1_mag =   (struct menu_obj){"MAGENTA",           49, 5, COLORED, COLOR_MAGENTA, &snake_1_cyan,  &snake_1_blue,  &snake_1,       &snake_2_red,   &snake_1_cyan,    s1_set_color};
    snake_1_cyan =  (struct menu_obj){"CYAN",              59, 5, COLORED, COLOR_CYAN,    &snake_1_white, &snake_1_mag,   &snake_1,       &snake_2_red,   &snake_1_white,   s1_set_color};
    snake_1_white = (struct menu_obj){"WHITE",             66, 5, COLORED, COLOR_WHITE,   &snake_1_red,   &snake_1_cyan,  &snake_1,       &snake_2_red,   &snake_2_color,   s1_set_color};
    snake_2_color = (struct menu_obj){"2nd snake color:",  1,  6, BOLD,    0,             NULL,           NULL,           NULL,           NULL,           &snake_2_red,     NULL};
    snake_2_red =   (struct menu_obj){"RED",               19, 6, COLORED, COLOR_RED,     &snake_2_green, &snake_2_white, &snake_1_red,   &start_sign,    &snake_2_green,   s2_set_color};
    snake_2_green = (struct menu_obj){"GREEN",             25, 6, COLORED, COLOR_GREEN,   &snake_2_yellow,&snake_2_red,   &snake_1_red,   &start_sign,    &snake_2_yellow,  s2_set_color};
    snake_2_yellow =(struct menu_obj){"YELLOW",            33, 6, COLORED, COLOR_YELLOW,  &snake_2_blue,  &snake_2_green, &snake_1_red,   &start_sign,    &snake_2_blue,    s2_set_color};
    snake_2_blue =  (struct menu_obj){"BLUE",              42, 6, COLORED, COLOR_BLUE,    &snake_2_mag,   &snake_2_yellow,&snake_1_red,   &start_sign,    &snake_2_mag,     s2_set_color};
    snake_2_mag =   (struct menu_obj){"MAGENTA",           49, 6, COLORED, COLOR_MAGENTA, &snake_2_cyan,  &snake_2_blue,  &snake_1_red,   &start_sign,    &snake_2_cyan,    s2_set_color};
    snake_2_cyan =  (struct menu_obj){"CYAN",              59, 6, COLORED, COLOR_CYAN,    &snake_2_white, &snake_2_mag,   &snake_1_red,   &start_sign,    &snake_2_white,   s2_set_color};
    snake_2_white = (struct menu_obj){"WHITE",             66, 6, COLORED, COLOR_WHITE,   &snake_2_red,   &snake_2_cyan,  &snake_1_red,   &start_sign,    &start_sign,      s2_set_color};
    start_sign =    (struct menu_obj){"START",             1,  8, BOLD,    0,             &start_sign,    &start_sign,    &snake_2_red,   &speed_1,       NULL,             ready_to_play};

//=========================================================================================================================================================================================
    
//----------------------------------VARIABLES-----------------------------------

    struct menu_obj * menu_ptr = &menu_sign;
    int ch;

//==============================================================================

//----------------------------------ACTION--------------------------------------
    
    //отрисовка меню
    while(menu_ptr){
        if(menu_ptr->style == BOLD){
            attron(A_BOLD);
        }
        if(menu_ptr->style == COLORED){
            attron(COLOR_PAIR(menu_ptr->parameter));
        }
        mvprintw( menu_ptr->y, menu_ptr->x, menu_ptr->text);
        if(menu_ptr->style == BOLD){
            attroff(A_BOLD);
        }
        if(menu_ptr->style == COLORED){
            attroff(COLOR_PAIR(menu_ptr->parameter));
        }
        menu_ptr = menu_ptr -> next_id;
    }
    show_config();

    menu_ptr = &speed_1;
    attron(A_REVERSE);
    mvprintw(menu_ptr->y, menu_ptr->x, menu_ptr->text);
    attroff(A_REVERSE);
    refresh();
    
    
    while(!ready_flg){
        ch = getch();

        //Возвращает пункт меню в исходное состояние
        if(menu_ptr->style == COLORED){
            attron(COLOR_PAIR(menu_ptr->parameter));
        }
        mvprintw(menu_ptr->y, menu_ptr->x, menu_ptr->text);
        if(menu_ptr->style == COLORED){
            attroff(COLOR_PAIR(menu_ptr->parameter));
        }

        //Обработка реакций на гуляния по меню
        switch(ch){
            case RIGHT_KEY: menu_ptr = menu_ptr->right_id; break;
            case LEFT_KEY:  menu_ptr = menu_ptr->left_id;  break;
            case DOWN_KEY:  menu_ptr = menu_ptr->lower_id; break;
            case UP_KEY:    menu_ptr = menu_ptr->upper_id; break;
            case ACK_KEY: case ENTER_KEY:
            {              
                menu_ptr->action(menu_ptr->parameter);
                show_config();            
                break;
            }
            case EXIT_KEY:  return FINAL;
            default: break;
        }
        //Выделение нового пункта меню
        attron(A_REVERSE);
        mvprintw(menu_ptr->y, menu_ptr->x, menu_ptr->text);
        attroff(A_REVERSE); 
        refresh();
    } 
    ready_flg = 0;
//=======================================================================================
    return GAME;
}