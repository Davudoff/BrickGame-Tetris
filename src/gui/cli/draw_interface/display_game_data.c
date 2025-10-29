#include "draw_interface.h"





void display_field(int ***field){
    for(int i = 0; i < HEIGHT; i++){
        int  g = 0;
        for(int j = 0; j < WIDTH; j++){
            if((*field)[i][j] == 2){
                mvaddwstr(i + 2, g + j + 2, L"█");
                g++;
                mvaddwstr(i + 2, g + j + 2, L"█");
            }
            else if((*field)[i][j] == 1){
                mvaddwstr(i + 2, g + j + 2, L"░");
                g++;
                mvaddwstr(i + 2, g + j + 2, L"░");
            }else{
                mvaddwstr(i + 2, g + j + 2, L" ");
                g++;
                mvaddwstr(i + 2, g + j + 2, L" ");
            }
        }
    }
}


static void display_next(int*** next_figure){
    for(int i = 0; i < 4; i++){
        int g = 0;
        for(int j = 0; j < 4; j++){
            if((*next_figure)[i][j]){
                mvaddwstr(i + 14, g + j + 24, L"░");
                g++;
                mvaddwstr(i + 14, g + j + 24, L"░");
            }
            else{
                mvaddwstr(i + 14, g + j + 24, L" ");
                g++;
                mvaddwstr(i + 14, g + j + 24, L" ");
            }
        }
    }
}




void display_game_data(GameInfo_t GameInfo){

    display_field(&GameInfo.field);
    display_next(&GameInfo.next);

    
    mvprintw(5, 25, "%c", ' ');
    mvprintw(5, 26, "%c", ' ');
    mvprintw(5, 27, "%c", ' ');
    mvprintw(5, 28, "%c", ' ');
    mvprintw(5, 24, "%d", GameInfo.level);
    mvprintw(8, 25, "%c", ' ');
    mvprintw(8, 26, "%c", ' ');
    mvprintw(8, 27, "%c", ' ');
    mvprintw(8, 28, "%c", ' ');
    mvprintw(8, 24, "%d", GameInfo.high_score);
    mvprintw(11, 25, "%c", ' ');
    mvprintw(11, 26, "%c", ' ');
    mvprintw(11, 27, "%c", ' ');
    mvprintw(11, 28, "%c", ' ');
    mvprintw(11, 24, "%d", GameInfo.score);

    if(GameInfo.pause){
        mvprintw(20, 25, "%c", 'P');
        mvprintw(20, 27, "%c", 'A');
        mvprintw(20, 29, "%c", 'U');
        mvprintw(20, 31, "%c", 'S');
        mvprintw(20, 33, "%c", 'E');
    }else{
        for(int i = 25; i < 34; i++)
            mvprintw(20, i, "%c", ' ');
    }


}