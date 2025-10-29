#ifndef INTERFACE
#define INTERFACE

#include <pthread.h>
#include "../../brick_game/tetris/source_code/tetris.h"
#include <ncurses.h>
#include "Draw_Interface/draw_interface.h"

#define Interface char***

UserAction_t entered_key(bool* keyHold);



#endif