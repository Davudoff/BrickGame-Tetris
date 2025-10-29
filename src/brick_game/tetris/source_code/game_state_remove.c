#include "tetris.h"
#include <stdlib.h>
#include <stdio.h>



static void field_memory_free(int ***field) {
    if (*field == NULL) return; // Проверяем, что указатель не NULL

    for (int i = 0; i < HEIGHT; i++) {
        free((*field)[i]); // Освобождаем память для каждой строки
    }

    free(*field); // Освобождаем основной массив
    *field = NULL; // Обнуляем указатель для предотвращения повторного освобождения
}

static void next_figure_memory_free(int ***next) {
    if (*next == NULL) return; // Проверяем, что указатель не NULL

    for (int i = 0; i < 4; i++) {
        free((*next)[i]); // Освобождаем память для каждой строки
    }

    free(*next); // Освобождаем основной массив
    *next = NULL; // Обнуляем указатель для предотвращения повторного освобождения
}


void game_state_remove(){
    field_memory_free(get_field_ptr());
    next_figure_memory_free(get_next_ptr());
}