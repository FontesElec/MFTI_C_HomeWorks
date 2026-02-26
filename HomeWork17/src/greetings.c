#include "greetings.h"
#include <locale.h>


static void screen_init(void){
    setlocale(LC_ALL, ".UTF-8");
    initscr();
    raw();                // Откдючаем line buffering
    noecho();             // Отключаем echo() режим при вызове getch
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    curs_set(FALSE);      // Отключаем курсор
    refresh();
    start_color();
    for(int i = COLOR_RED; i <= COLOR_WHITE; i++){
        init_pair(i, i, COLOR_BLACK);
    }
}

activity_t greetings_page(void){
    screen_init();
    int x = 1;
    int y = 2;
    mvprintw(y, x,"WELCOME TO THE SNAKE GAME.");
    y++;
    y++;
    mvprintw(y, x,"* Use arrows for control");
    y++;
    mvprintw(y, x,"* Press ENTER for selection");
    y++;
    mvprintw(y, x, "* Press 'F10' for EXIT");
    y++;
    y++;
    mvprintw(y, x,"Press any key to continue");
    refresh();
    int ch = getch();
    if(ch == EXIT_KEY){
        return EXIT;
    }
    return MAIN_MENU;
}