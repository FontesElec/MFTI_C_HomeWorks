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