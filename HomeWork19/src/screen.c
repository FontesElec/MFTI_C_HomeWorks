#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h> // for toupper()
#include <locale.h>
#include "screen.h"
#include "snake.h"
#include "greetings.h"
#include "main_menu.h"
#include "game.h"
#include "game_over.h"

extern Screen_t* myScreen;

Screen_t* new_screen(void){
    static Screen_t new_screen;
    myScreen = &new_screen;
    //привязка страниц игры
    new_screen.activity[GREETINGS] = greetings_page;
    new_screen.activity[MAIN_MENU] = main_menu_page;
    new_screen.activity[GAME] = game_page;
    new_screen.activity[GAME_OVER] = game_over_page;
    new_screen.activity[FINAL] = screen_destruction;
    //базовые настройки игры
    new_screen.snakes = 1;
    new_screen.snake_list = NULL;
    new_screen.speed = 1;
    //создание мест под две змеи по умолчанию
    new_screen.snake_list = calloc(1, sizeof(struct Snake));
    new_screen.snake_list->next = calloc(1, sizeof(struct Snake));
    return &new_screen;
}

activity_t screen_destruction(void){
    //сюда добавить деинициализацию всех динамически создаваемых объектов
    #warning NEED TO WRITE REALISATION
    return EXIT;
}

