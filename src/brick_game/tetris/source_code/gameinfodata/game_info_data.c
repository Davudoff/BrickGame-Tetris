#include "game_info_data.h"


static GameInfo_t GameInfo; 

GameInfo_t updateCurrentState(){
    return GameInfo;
}

int*** get_field_ptr(){
    return &GameInfo.field;
}
int*** get_next_ptr(){
    return &GameInfo.next;
}
int get_score(){
    return GameInfo.score;
}
int get_high_score(){
    return GameInfo.high_score;
}
int get_level(){
    return GameInfo.level;
}
int get_speed(){
    return GameInfo.speed;
}
int get_pause(){
    return GameInfo.pause;
}

void set_field(int ***newField){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            GameInfo.field[i][j] = (*newField)[i][j];
        }
    }
}
void set_next(int*** nextFigure){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            GameInfo.next[i][j] = (*nextFigure)[i][j];
        }
    }
}
void set_score(int val){
    GameInfo.score = val;
}
void set_high_score(int val){
    GameInfo.high_score = val;
}
void set_level(int val){
    GameInfo.level = val;
}
void set_speed(int val){
    GameInfo.speed = val;
}
void set_pause(int val){
    GameInfo.pause = val;
}


