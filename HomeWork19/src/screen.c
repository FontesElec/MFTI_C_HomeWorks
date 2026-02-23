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

extern Screen_t* myScreen;

//Custom delay instead timeout and usleep functions
static void c_delay_ms(double delay){
    clock_t begin = clock();
    while((double)(clock() - begin) < delay){}
}

static void init_snake(Screen_t* my_screen){

}

static activity_t game_page(void){
    printf("%s", "game\n");

    return GAME_OVER;
}

static activity_t game_over_page(void){
    printf("%s", "game_over\n");
    return EXIT;
}

Screen_t* new_screen(void){
    static Screen_t new_screen;
    myScreen = &new_screen;
    new_screen.activity[GREETINGS] = greetings_page;
    new_screen.activity[MAIN_MENU] = main_menu_page;
    new_screen.activity[GAME] = game_page;
    new_screen.activity[GAME_OVER] = game_over_page;
    new_screen.snakes = 1;
    new_screen.snake_list = NULL;
    new_screen.speed = 1;
    return &new_screen;
}

