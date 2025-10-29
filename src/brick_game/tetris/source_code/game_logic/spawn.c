#include "../tetris.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

typedef enum {
    Red = 1,
    Orange,
    Yellow,
    Pink,
    Green,
    Blue,
    Purple
} Figure_t;


bool next_is_null(){
    int*** next = get_next_ptr();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if((*next)[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

void newField(int*** nextFigure){
    int*** newField = get_field_ptr();

    for(int i = 0; i < 4; i++){
        for(int  j = 0; j < 4; j++){
            if((*nextFigure)[i][j] == 1)
                (*newField)[i][j+3] = 1;
        }
    }
    
}


void figure_Generation(int*** nextFigure){
    static int lastFigure = -1;  // Инициализируем предыдущее значение случайного числа
    Figure_t figureRandChoose;

    // Генерируем случайное число, пока оно не будет отличаться от предыдущего
    do {
        figureRandChoose = (rand() % 7) + 1;
    } while ((int)figureRandChoose == lastFigure);

    lastFigure = (int)figureRandChoose;  // Обновляем предыдущее значение

    // Обнуляем массив
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            (*nextFigure)[i][j] = 0;
        }
    }


    switch(figureRandChoose){
        case Red:{
            for(int i = 0; i < 4; i++){
                (*nextFigure)[0][i] = 1;
            }
            break;
        }
        case Orange:{
            (*nextFigure)[0][0] = 1;
            (*nextFigure)[1][0] = 1;
            (*nextFigure)[1][1] = 1;
            (*nextFigure)[1][2] = 1;
            break;
        }
        case Yellow:{
            (*nextFigure)[0][2] = 1;
            (*nextFigure)[1][0] = 1;
            (*nextFigure)[1][1] = 1;
            (*nextFigure)[1][2] = 1;
            break;
        }
        case Pink:{
            (*nextFigure)[0][1] = 1;
            (*nextFigure)[0][2] = 1;
            (*nextFigure)[1][1] = 1;
            (*nextFigure)[1][2] = 1;
            break;
        }
        case Green:{
            (*nextFigure)[0][1] = 1;
            (*nextFigure)[0][2] = 1;
            (*nextFigure)[1][0] = 1;
            (*nextFigure)[1][1] = 1;
            break;
        }
        case Blue:{
            (*nextFigure)[0][1] = 1;
            (*nextFigure)[1][0] = 1;
            (*nextFigure)[1][1] = 1;
            (*nextFigure)[1][2] = 1;
            break;
        }
        case Purple:{
            (*nextFigure)[0][0] = 1;
            (*nextFigure)[0][1] = 1;
            (*nextFigure)[1][1] = 1;
            (*nextFigure)[1][2] = 1;
            break;
        }   
    }

}



void spawn(){
    int** nextFigure = (int**)malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++) {
        nextFigure[i] = (int*)malloc(4 * sizeof(int));
        if (nextFigure[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(nextFigure[j]);
            }
            free(nextFigure);
        }
    }

    figure_Generation(&nextFigure);

    if(next_is_null()){
        newField(&nextFigure);
        figure_Generation(&nextFigure);
    }
    else{
        newField(get_next_ptr());
    }

    set_next(&nextFigure);
}
