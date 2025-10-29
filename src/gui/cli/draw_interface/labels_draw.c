#include "draw_interface.h"




static void tetris(){
    mvprintw(2, 24, "%c", 'T');
    mvprintw(2, 25, "%c", ' ');
    mvprintw(2, 26, "%c", 'E');
    mvprintw(2, 27, "%c", ' ');
    mvprintw(2, 28, "%c", 'T');
    mvprintw(2, 29, "%c", ' ');
    mvprintw(2, 30, "%c", 'R');
    mvprintw(2, 31, "%c", ' ');
    mvprintw(2, 32, "%c", 'I');
    mvprintw(2, 33, "%c", ' ');
    mvprintw(2, 34, "%c", 'S');
}

static void level(){
    mvprintw(4, 24, "%c", 'L');
    mvprintw(4, 25, "%c", ' ');
    mvprintw(4, 26, "%c", 'E');
    mvprintw(4, 27, "%c", ' ');
    mvprintw(4, 28, "%c", 'V');
    mvprintw(4, 29, "%c", ' ');
    mvprintw(4, 30, "%c", 'E');
    mvprintw(4, 31, "%c", ' ');
    mvprintw(4, 32, "%c", 'L');
    mvprintw(4, 33, "%c", ':');
}

static void record(){
    mvprintw(7, 24, "%c", 'R');
    mvprintw(7, 25, "%c", ' ');
    mvprintw(7, 26, "%c", 'E');
    mvprintw(7, 27, "%c", ' ');
    mvprintw(7, 28, "%c", 'C');
    mvprintw(7, 29, "%c", ' ');
    mvprintw(7, 30, "%c", 'O');
    mvprintw(7, 31, "%c", ' ');
    mvprintw(7, 32, "%c", 'R');
    mvprintw(7, 33, "%c", ' ');
    mvprintw(7, 34, "%c", 'D');
    mvprintw(7, 35, "%c", ':');
}

static void score(){
    mvprintw(10, 24, "%c", 'S');
    mvprintw(10, 25, "%c", ' ');
    mvprintw(10, 26, "%c", 'C');
    mvprintw(10, 27, "%c", ' ');
    mvprintw(10, 28, "%c", 'O');
    mvprintw(10, 29, "%c", ' ');
    mvprintw(10, 30, "%c", 'R');
    mvprintw(10, 31, "%c", ' ');
    mvprintw(10, 32, "%c", 'E');
    mvprintw(10, 33, "%c", ':');
}

static void next(){
    mvprintw(13, 24, "%c", 'N');
    mvprintw(13, 25, "%c", ' ');
    mvprintw(13, 26, "%c", 'E');
    mvprintw(13, 27, "%c", ' ');
    mvprintw(13, 28, "%c", 'X');
    mvprintw(13, 29, "%c", ' ');
    mvprintw(13, 30, "%c", 'T');
    mvprintw(13, 31, "%c", ':');
}


void labels_draw(){
    tetris();
    level();
    record();
    score();
    next();
}