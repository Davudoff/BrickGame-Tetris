#include "draw_interface.h"


#define FRAME_START I_WIDTH - 13
#define FRAME_FINISH I_WIDTH - 1
#define TF_WIDTH I_WIDTH - 30
#define TF_HIGHT I_HEIGHT - 20


static void angles(){
    mvaddch(1, FRAME_START, ACS_ULCORNER);
    mvaddch(1, FRAME_FINISH, ACS_URCORNER); 
    mvaddch(3, FRAME_START, ACS_LLCORNER);     
    mvaddch(3, FRAME_FINISH, ACS_LRCORNER); 
}

static void horizontal_lines(){
    for(int x = FRAME_START + 1; x < FRAME_FINISH; x++){
        mvaddch(1, x, ACS_HLINE);
        mvaddch(3, x, ACS_HLINE);
    }
}

static void vertical_lines(){
    mvaddch(2, FRAME_START, ACS_VLINE);
    mvaddch(2, FRAME_FINISH, ACS_VLINE);
}


void frame_for_tetris_label_draw(){
    angles();
    horizontal_lines();
    vertical_lines();
}