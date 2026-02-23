#include <inttypes.h>

typedef struct{
    uint16_t t;
    struct Tail* next;
}Tail;


struct Snake{
    struct Snake* next;
    uint8_t color;
    struct Tail* my_tail;
};
