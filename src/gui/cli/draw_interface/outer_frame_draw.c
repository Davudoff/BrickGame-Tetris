#include "draw_interface.h"


static void angles(){
    mvaddch(0, 0, ACS_ULCORNER);
    mvaddch(0, I_WIDTH, ACS_URCORNER); 
    mvaddch(I_HEIGHT, 0, ACS_LLCORNER);     
    mvaddch(I_HEIGHT, I_WIDTH, ACS_LRCORNER); 
}

static void horizontal_lines(){
    for(int x = 1; x < I_WIDTH; x++){
        mvaddch(0, x, ACS_HLINE);
        mvaddch(I_HEIGHT, x, ACS_HLINE);
    }
}

static void vertical_lines(){
    for(int y = 1; y < I_HEIGHT; y++){
        mvaddch(y, 0, ACS_VLINE);
        mvaddch(y, I_WIDTH, ACS_VLINE);
    }
}

void outer_frame_draw(){
    angles();
    horizontal_lines();
    vertical_lines();
}