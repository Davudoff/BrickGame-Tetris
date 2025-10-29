#include "draw_interface.h"




void draw_interface(GameInfo_t GameInfo){
    //clear();
    start_color();
    
    outer_frame_draw();
    inner_frame_draw();
    frame_for_tetris_label_draw();

    labels_draw();

    display_game_data(GameInfo);
    move(I_HEIGHT + 1, 0);
    


    refresh();
}
