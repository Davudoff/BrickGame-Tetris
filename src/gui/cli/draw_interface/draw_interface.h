#ifndef DRAW_INTERFACE
#define DRAW_INTERFACE
#include <ncurses.h>
#include "../../../brick_game/tetris/source_code/tetris.h"


#define I_WIDTH 36
#define I_HEIGHT 23


void draw_interface(GameInfo_t GameInfo);

void outer_frame_draw();
void inner_frame_draw();
void frame_for_tetris_label_draw();
void labels_draw();

void display_game_data(GameInfo_t GameInfo);













#endif 