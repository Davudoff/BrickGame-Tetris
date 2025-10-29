#include "../tetris.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


void form_a_field(int*** field){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if((*field)[i][j] == 1){
                (*field)[i][j] = 2;
            }
        }
    }
}


int is_line_complete(int* field){
    int lineCompleteFlag = 1;
    for(int i = 0; i < WIDTH; i++){
        if(field[i] != 2){
            lineCompleteFlag = 0;
        }
    }
    return lineCompleteFlag;
}
void delete_line(int*** field, int row){
    for(int i = row; i >= 1; i--){
        for(int j = 0; j < WIDTH; j++){
            (*field)[i][j] = (*field)[i - 1][j];
        }
    }
}

void delete_complete_line(int*** field) {
    int delLineCount = 0;

    for (int i = HEIGHT - 1; i >= 0; i--) {
        if (is_line_complete((*field)[i])) {
            delete_line(field, i);
            delLineCount++;
            i++; // Проверяем снова ту же строку, так как все верхние строки сдвинулись вниз
        }
    }

    // Устанавливаем очки в зависимости от количества удаленных строк
    switch (delLineCount) {
        case 1: set_score(get_score() + 100); break;
        case 2: set_score(get_score() + 300); break;
        case 3: set_score(get_score() + 700); break;
        case 4: set_score(get_score() + 1500); break;
    }
    if(get_score() > get_high_score()) set_high_score(get_score());
    if(get_speed() * 600 < get_score() && get_speed() <= 9){
        set_level(get_level() + 1);
        set_speed(get_speed() + 1);
    } 
    update_interval(get_speed());
}


int attaching(){
    int*** field = get_field_ptr();

    
    for(int i = 0; i < WIDTH; i++){
        if((*field)[0][i] == 2){
            return 1;
        }
    }

    form_a_field(field);
    delete_complete_line(field);
    


    return 0;
}