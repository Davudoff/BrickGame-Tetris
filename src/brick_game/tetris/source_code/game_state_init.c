#include "tetris.h"
#include <stdlib.h>
#include <stdio.h>



int field_memory_allocate(int ***field) {
    int retFlag = 0;
    *field = (int**)malloc(HEIGHT * sizeof(int*));
    if (*field == NULL) return 1; // Если не удалось выделить память под строки

    for (int i = 0; i < HEIGHT && retFlag == 0; i++) {
        (*field)[i] = (int*)malloc(WIDTH * sizeof(int));
        if ((*field)[i] == NULL) {
            retFlag = 1;
            // Освобождаем уже выделенную память в случае ошибки
            for (int j = 0; j < i; j++) {
                free((*field)[j]);
            }
            free(*field);
        }
    }

    return retFlag;
}

int field_init(int ***field){
    if(field_memory_allocate(field)) return 1;

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            (*field)[i][j] = OFF;
        }
    }

    return 0;
}


int next_figure_memory_allocate(int ***next) {
    int retFlag = 0;
    *next = (int**)malloc(4 * sizeof(int*));
    if (*next == NULL) return 1; // Если не удалось выделить память

    for (int i = 0; i < 4 && retFlag == 0; i++) {
        (*next)[i] = (int*)malloc(4 * sizeof(int));
        if ((*next)[i] == NULL) {
            retFlag = 1;
            // Освобождаем уже выделенную память в случае ошибки
            for (int j = 0; j < i; j++) {
                free((*next)[j]);
            }
            free(*next);
        }
    }

    return retFlag;
}
int next_figure_init(int ***next){
    if(next_figure_memory_allocate(next)) return 1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            (*next)[i][j] = OFF;
        }
    }

    return 0;
}


void write_high_score() {
    const char* file_path = "../../brick_game/tetris/Resource/HighScore.txt";

    // Попытка открыть файл на чтение
    FILE* file = fopen(file_path, "r"); 
    
    // Если файл не открылся (не существует), создаем его
    if (file == NULL) {
        file = fopen(file_path, "w"); // Открываем файл на запись
        if (file == NULL) {
            perror("Ошибка создания файла");
            return; // Завершаем функцию, если файл не удалось создать
        }
        int initialScore = 0;  // Начальное значение для high score
        fprintf(file, "%d\n", initialScore);  // Записываем в файл
        fclose(file);  // Закрываем файл
        printf("Файл был создан и инициализирован с начальным значением: %d\n", initialScore);
        return;
    }

    // Чтение текущего high score из файла
    int highScore = 0;
    if (fscanf(file, "%d", &highScore) != 1) {
        fprintf(stderr, "Ошибка: файл не содержит корректного числа\n");
        fclose(file);
        return;
    }

    // Устанавливаем high score
    set_high_score(highScore);

    fclose(file); // Закрываем файл
}

int game_state_init(){
    int retFlag = 0;
    retFlag |= field_init(get_field_ptr());

    retFlag |= next_figure_init(get_next_ptr());

    set_score(0);   
    write_high_score();
    set_level(1);
    set_speed(1);
    set_pause(ON);

    return retFlag;
}
