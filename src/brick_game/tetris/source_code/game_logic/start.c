#include "../tetris.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int start(UserAction_t action){
    int runGame_F = 0;
    
    if(action == Start){
        game_state_remove();
        game_state_init();
        set_pause(0);

        last_time = clock();
        update_interval(get_speed());

        
        runGame_F = 1;
    }

    return runGame_F;
}
