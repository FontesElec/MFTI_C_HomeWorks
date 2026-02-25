#include <inttypes.h>

struct Tail{
    uint16_t tail_x;
    uint16_t tail_y;
    struct Tail* next;
};

typedef enum{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
}direction_t;


struct Snake{
    uint16_t head_x;
    uint16_t head_y;
    uint8_t color;
    direction_t direction;
    struct Tail* my_tail;
    struct Snake* next;
};

void init_snake(struct Snake* my_snake);
void draw_snake(struct Snake* my_snake);
void move_snake(struct Snake* my_snake);