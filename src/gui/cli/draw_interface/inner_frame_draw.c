#include "draw_interface.h"

#define IN_WIDTH I_WIDTH - 14
#define IN_HIGHT I_HEIGHT - 1


static void angles(){
    mvaddch(1, 1, ACS_ULCORNER);
    mvaddch(1, IN_WIDTH, ACS_URCORNER); 
    mvaddch(IN_HIGHT, 1, ACS_LLCORNER);     
    mvaddch(IN_HIGHT, IN_WIDTH, ACS_LRCORNER); 
}

static void horizontal_lines(){
    for(int x = 2; x < IN_WIDTH; x++){
        mvaddch(1, x, ACS_HLINE);
        mvaddch(IN_HIGHT, x, ACS_HLINE);
    }
}

static void vertical_lines(){
    for(int y = 2; y < IN_HIGHT; y++){
        mvaddch(y, 1, ACS_VLINE);
        mvaddch(y, IN_WIDTH, ACS_VLINE);
    }
}


void inner_frame_draw(){
    angles();
    horizontal_lines();
    vertical_lines();
}