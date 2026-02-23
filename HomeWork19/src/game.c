#include "game.h"
#include <time.h>

//Custom delay instead timeout and usleep functions
static void c_delay_ms(double delay){
    clock_t begin = clock();
    while((double)(clock() - begin) < delay){};
}

static void init_snake(Screen_t* my_screen){

}

activity_t game_page(void){
    printf("%s", "game\n");

    return GAME_OVER;
}

