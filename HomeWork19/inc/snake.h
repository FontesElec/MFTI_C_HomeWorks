#include <inttypes.h>

//Границы экрана для служебной информации
#define RIGHT_BORDER 20
#define LOWER_BORDER 3

struct Tail{
    uint16_t tail_x;
    uint16_t tail_y;
    struct Tail* next;
};

typedef enum{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
    NO_DIR
}direction_t;

typedef struct{
    int key;
    direction_t direction;
}keys_t;


struct Snake{
    uint16_t head_x;
    uint16_t head_y;
    uint8_t color;
    uint8_t points;
    const keys_t* controll_keys;
    const char* head_symbol;
    const char* tail_symbol;
    direction_t direction;
    struct Tail* my_tail;
    struct Snake* next;
};

void init_snake(struct Snake* my_snake, uint8_t snake_num);
void move_snake(struct Snake* my_snake);
uint8_t snake_self_collision(struct Snake* my_snake);
uint8_t snake_vs_snake_collision(struct Snake* my_snake, struct Snake* other_snake);
void grow_snake(struct Snake* my_snake);
void tail_destruction(struct Snake* my_snake);
void snake_destruction(struct Snake* my_snake);