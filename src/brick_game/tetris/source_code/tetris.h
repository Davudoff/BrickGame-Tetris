#ifndef TETRIS
#define TETRIS

#include "GameInfoData/game_info_data.h"
#include <stdbool.h>
#include <time.h>

extern double interval;
extern time_t last_time;
extern time_t current_time;

typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action,
    NONE
} UserAction_t;



void userInput(UserAction_t action, bool hold);
int start(UserAction_t action);
void spawn();
int moving(UserAction_t action, bool hold);
int attaching();

int game_state_init();
void game_state_remove();
void high_score_save();
void update_interval(int speed);


#endif