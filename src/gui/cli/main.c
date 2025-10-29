#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  // Для функции sleep
#include "interface.h"
#include "../../brick_game/tetris/source_code/tetris.h"
#include <locale.h> // Для поддержки Unicode



void* run_frontend(){
    bool keyHold = 0;
    while(true){
        draw_interface(updateCurrentState());
        userInput(entered_key(&keyHold), keyHold);
        napms(10);
        
    }
}


int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "");

    initscr();
    curs_set(0); // Скрываем курсор
    noecho(); // Отключаем ввод символов в терминал
    cbreak(); // Включаем мгновенное чтение с клавиатуры
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE); // Ввод без блокировки

    game_state_init();

    run_frontend();

    endwin();
    game_state_remove();

    return 0;
}


// сделать отображение полей на итерфэйс и понять нахуя нам вообще многопоточность