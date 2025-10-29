#include "../tetris.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

double interval = 0.01; // Интервал для текущей скорости
double minInterval = 0.001; // Минимальное время между движениями
double maxInterval = 0.01;  // Максимальное время между движениями

clock_t last_time;
clock_t current_time;

void update_interval(int speed) {
    // Рассчитываем интервал в зависимости от скорости
    interval = maxInterval - (get_speed() - 1.0) * (maxInterval - minInterval) / 9.0;
}

int check_right_edge(int ***field){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if((*field)[i][j] == 1 && (j == 9 || (*field)[i][j + 1] == 2)){
                return 0;
            }
        }
    }
    return 1;
}

int check_left_edge(int ***field){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if((*field)[i][j] == 1 && (j == 0 || (*field)[i][j - 1] == 2)){
                return 0;
            }
        }
    }
    return 1;
}



void leftShift(int ***field){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if((*field)[i][j] == 1){
                (*field)[i][j] = 0;
                (*field)[i][j - 1] = 1;
            }
        }
    }
}

void rightShift(int ***field){
    for(int i = HEIGHT - 1; i >= 0; i--){
        for(int j = WIDTH - 1; j >= 0; j--){
            if((*field)[i][j] == 1){
                (*field)[i][j] = 0;
                (*field)[i][j + 1] = 1;
            }
        }
    }
}


void shifting(int ***field){

    for(int i = HEIGHT - 1; i >= 0; i--){
        for(int j = 0; j < WIDTH; j++){
            if((*field)[i][j] == 1){
                (*field)[i][j] = 0;
                (*field)[i + 1][j] = 1;
            }
        }
    }
}










void rotation(int ***field) {
    int minRow = HEIGHT, maxRow = -1;
    int minCol = WIDTH, maxCol = -1;

    // Найти границы текущей фигуры
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if ((*field)[i][j] == 1) {
                if (i < minRow) minRow = i;
                if (i > maxRow) maxRow = i;
                if (j < minCol) minCol = j;
                if (j > maxCol) maxCol = j;
            }
        }
    }

    // Вычисляем центр вращения
    int centerRow = (minRow + maxRow) / 2;
    int centerCol = (minCol + maxCol) / 2;

    // Создать временное поле для проверки вращения
    int tempField[HEIGHT][WIDTH] = {0};
    int canRotate = 1;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if ((*field)[i][j] == 1) {
                int newRow = centerRow + (j - centerCol);
                int newCol = centerCol - (i - centerRow);

                // Проверка границ и препятствий
                if (newRow < 0 || newRow >= HEIGHT || newCol < 0 || newCol >= WIDTH || (*field)[newRow][newCol] == 2) {
                    canRotate = 0;
                } else {
                    tempField[newRow][newCol] = 1;
                }
            }
        }
    }

    // Если вращение возможно, применяем его
    if (canRotate) {
        // Удаляем старую фигуру с поля
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if ((*field)[i][j] == 1) {
                    (*field)[i][j] = 0;
                }
            }
        }

        // Применяем временное поле
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (tempField[i][j] == 1) {
                    (*field)[i][j] = 1;
                }
            }
        }
    }
}

int touched(){
    int*** field = get_field_ptr();
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if((*field)[i][j] == 1 && (i == HEIGHT - 1 || (*field)[i + 1][j] == 2)){
                return 1;
            }
        }
    }
    return 0;
}


int moving(UserAction_t action, bool hold){
    int*** field = get_field_ptr();
    switch (action){
        case (Left):{
            if(check_left_edge(field))
                leftShift(field);
            break;
        }
        case (Right):{
            if(check_right_edge(field))
                rightShift(field);
            break;
        }
        case (Down):{
            shifting(field);
            break;
        }
        case (Action):{
            rotation(field);
            break;
        }
    }

    if(touched()) return 1;

    current_time = clock(); // Получаем текущее время
    double elapsed_time = ((double)(current_time - last_time)) / CLOCKS_PER_SEC; // Рассчитываем прошедшее время

    if (elapsed_time >= interval) {
        shifting(field);
        last_time = current_time; // Обновляем время последнего шага
    }

    
    return 0;
}