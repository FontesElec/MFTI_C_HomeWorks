#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

int main(void){
    Screen_t* myScreen_p = new_screen();
    activity_t myActivity = GREETINGS;
    while(myActivity != EXIT){
        myActivity = myScreen_p->activity[myActivity]();
    }
}


// #define MIN_Y  2
// enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
// enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10};

// //Custom delay instead timeout and usleep functions
// void c_delay_ms(double delay){
//     clock_t begin = clock();
//     while((double)(clock() - begin) < delay){}
// }

// // Здесь храним коды управления змейкой
// struct control_buttons
// {
//     int down;
//     int up;
//     int left;
//     int right;
// }control_buttons;

// struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};

// /*
//  Голова змейки содержит в себе
//  x,y - координаты текущей позиции
//  direction - направление движения
//  tsize - размер хвоста
//  *tail -  ссылка на хвост
//  */
// typedef struct snake_t
// {
//     int x;
//     int y;
//     int direction;
//     size_t tsize;
//     struct tail_t *tail;
//     struct control_buttons controls;
// } snake_t;

// /*
//  Хвост это массив состоящий из координат x,y
//  */
// typedef struct tail_t
// {
//     int x;
//     int y;
// } tail_t;

// void initTail(struct tail_t t[], size_t size)
// {
//     struct tail_t init_t={0,0};
//     for(size_t i=0; i<size; i++)
//     {
//         t[i]=init_t;
//     }
// }
// void initHead(struct snake_t *head, int x, int y)
// {
//     head->x = x;
//     head->y = y;
//     head->direction = RIGHT;
// }

// void initSnake(snake_t *head, size_t size, int x, int y)
// {
// tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
//     initTail(tail, MAX_TAIL_SIZE);
//     initHead(head, x, y);
//     head->tail = tail; // прикрепляем к голове хвост
//     head->tsize = size+1;
//     head->controls = default_controls;
// }

// /*
//  Движение головы с учетом текущего направления движения
//  */
// void go(struct snake_t *head)
// {
//     char ch = '@';
//     int max_x=0, max_y=0;
//     getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
//     mvprintw(head->y, head->x, " "); // очищаем один символ
//     switch (head->direction)
//     {
//         case LEFT:
//             if(head->x <= 0) // Циклическое движение, чтобы не
// // уходить за пределы экрана
//                 head->x = max_x;
//             mvprintw(head->y, --(head->x), "%c", ch);
//         break;
//         case RIGHT:
//             mvprintw(head->y, ++(head->x), "%c", ch);
//         break;
//         case UP:
//             mvprintw(--(head->y), head->x, "%c", ch);
//         break;
//         case DOWN:
//             mvprintw(++(head->y), head->x, "%c", ch);
//         break;
//         default:
//         break;
//     }
//     refresh();
// }

// void changeDirection(struct snake_t* snake, const int32_t key)
// {
//     if (key == snake->controls.down)
//         snake->direction = DOWN;
//     else if (key == snake->controls.up)
//         snake->direction = UP;
//     else if (key == snake->controls.right)
//         snake->direction = RIGHT;
//     else if (key == snake->controls.left)
//         snake->direction = LEFT;
// }

// /*
//  Движение хвоста с учетом движения головы
//  */
// void goTail(struct snake_t *head)
// {
//     char ch = '*';
//     mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
//     for(size_t i = head->tsize-1; i>0; i--)
//     {
//         head->tail[i] = head->tail[i-1];
//         if( head->tail[i].y || head->tail[i].x)
//             mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
//     }
//     head->tail[0].x = head->x;
//     head->tail[0].y = head->y;
// }

// typedef struct{


// } Snakes;

// void init_snake(void){


// };

// void destroy_snake(void){

// };

// void action(char ch){

// };


// typedef struct{
//     void(*init_screen)(void);
//     void(*deinit_screen)(Screen* obj);
//     void(*new_snake)(void);
//     void(*destroy_snake)(void);
//     void(*action)(char ch);
//     Snakes* snakes_list;
// }Screen;

// void deinit_screen(Screen* obj){
//     free(obj);
//     printf("%s", "screen deinitialized\n");
// };

// void init_screen(void){
//     // initscr();
//     // keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
//     // raw();                // Откдючаем line buffering
//     // noecho();            // Отключаем echo() режим при вызове getch
//     // curs_set(FALSE);    //Отключаем курсор
//     printf("%s", "screen initialized\n");
// }


// Screen new_screen(void){
//     Screen new_screen;
//     new_screen.init_screen = init_screen;
//     new_screen.deinit_screen = deinit_screen;
//     new_screen.new_snake = init_snake;
//     new_screen.destroy_snake = destroy_snake;
//     new_screen.action = action;
//     printf("%s", "screen obj initialized\n");
//     return new_screen;
// }


// int main()
// {
//     Screen myScreen = new_screen();
//     myScreen.init_screen();

//     //myScreen.deinit_screen(myScreen.self);
    

//     // snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
//     // initSnake(snake,START_TAIL_SIZE,10,10);
//     // initscr();
//     // keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
//     // raw();                // Откдючаем line buffering
//     // noecho();            // Отключаем echo() режим при вызове getch
//     // curs_set(FALSE);    //Отключаем курсор
//     // mvprintw(0, 0,"Use arrows for control. Press 'F10' for EXIT");
//     // timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
//     // int key_pressed=0;
//     // while( key_pressed != STOP_GAME )
//     // {
//     //     key_pressed = getch(); // Считываем клавишу
//     //     go(snake);
//     //     goTail(snake);
//     //     timeout(100); // Задержка при отрисовке
//     //     changeDirection(snake, key_pressed);
//     // }
//     // free(snake->tail);
//     // free(snake);
//     // endwin(); // Завершаем режим curses mod
//     return 0;
// }