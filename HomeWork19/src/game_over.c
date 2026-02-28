#include "game_over.h"
#include "common.h"
#include "snake.h"
#include <stdlib.h>
#include <ncurses/ncurses.h>

extern Screen_t* myScreen;

void tails_destruction(void){
    struct Snake* s_ptr = myScreen->snake_list;
    while(s_ptr){
        tail_destruction(s_ptr);
        s_ptr = s_ptr -> next;
    }    
}

activity_t game_over_page(void){
    clear();
    food_destruction();
    tails_destruction();
    struct Snake* s_ptr = myScreen -> snake_list;
    uint8_t cntr = 0;
    uint8_t leader = 0;
    uint8_t max_points = 0;
    while(s_ptr){
        if(max_points < s_ptr->points){
            max_points = s_ptr->points;
            leader = cntr;
        }
        cntr++;
        s_ptr = s_ptr->next;
    }
    attron(COLOR_PAIR(1));
    mvprintw(3,getmaxx(stdscr)/2 - 6, "GAME OVER");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvprintw(4,getmaxx(stdscr)/2 - 7, "Snake %d win", leader);
    attroff(COLOR_PAIR(2));
    mvprintw(7,getmaxx(stdscr)/2 - 15, "press Q to return in main menu");
    mvprintw(8,getmaxx(stdscr)/2 - 9, "press F10 to exit");
    refresh();

    nodelay(stdscr, FALSE);
    int ch = getch();
    while(1){
        switch (ch){
            case EXIT_KEY:                              return FINAL; break;
            case 'q': case 'Q': case 1081: case 1049:   return MAIN_MENU; break;
            default: break;
        }
    }   
    return EXIT;
}