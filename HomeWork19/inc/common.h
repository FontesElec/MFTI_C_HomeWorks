#include <stdint.h>
#include "ncurses/ncurses.h"

#pragma once

typedef enum{
    GREETINGS,
    MAIN_MENU,
    GAME,
    GAME_OVER,
    EXIT,
}activity_t;


typedef enum {
    EXIT_KEY = KEY_F(10),
    ACK_KEY = 10,
    ENTER_KEY = KEY_ENTER,
    UP_KEY = KEY_UP,
    DOWN_KEY = KEY_DOWN,
    RIGHT_KEY = KEY_RIGHT,
    LEFT_KEY = KEY_LEFT
} menu_keys_t;

typedef  activity_t (*function_ptr)(void);
typedef struct Screen{
    function_ptr activity[4];
    uint8_t snakes;
    uint8_t speed;
    struct Snake* snake_list;
} Screen_t;

