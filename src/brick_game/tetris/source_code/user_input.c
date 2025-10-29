#include "tetris.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>


void update_high_score(int newScore) {
    const char* file_path = "../../brick_game/tetris/Resource/HighScore.txt";

    // Открываем файл для записи (режим "w" перезапишет файл)
    FILE* file = fopen(file_path, "w");
    if (file == NULL) {
        perror("Ошибка открытия файла для записи");
        return;
    }

    // Записываем новое значение в файл
    fprintf(file, "%d\n", newScore);

    // Закрываем файл
    fclose(file);
}


void game_over(){
    int*** field = get_field_ptr();
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            (*field)[i][j] = 0;
        }
    }
    int*** next = get_next_ptr();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            (*next)[i][j] = 0;
        }
    }

    set_score(0);  
    update_high_score(get_high_score()); 
    set_level(1);
    set_speed(1);
    set_pause(1);
}


void userInput(UserAction_t action, bool hold){
    
    int startFlag = start(action);
    if(action == Pause) set_pause(!get_pause());
    if(action == Terminate) game_over();

    if (!get_pause()){
        if(startFlag) spawn();

        if(moving(action, hold)){
            if(attaching()){
                game_over();
            }
            else{
                spawn();
            }
        }


    }


}









