#include <inttypes.h>

typedef struct{
    uint16_t tail_x;
    uint16_t tail_y;
    struct Tail* next;
}Tail;

typedef enum{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
}direction_t;


struct __attribute__ ((packed)) Snake{
    uint16_t head_x;
    uint16_t head_y;
    uint8_t color;
    direction_t direction;
    struct Tail* my_tail;
    struct Snake* next;
};
