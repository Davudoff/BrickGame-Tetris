#include "interface.h"



UserAction_t entered_key(bool* keyHold) { 
    UserAction_t action = NONE;
    *keyHold = false; 

    int key = getch(); 

    switch (key) {
        case KEY_UP:
        case 'W':
        case 'w':
            action = Up;
            break;
        case KEY_DOWN:
        case 'S':
        case 's':
            action = Down;
            break;
        case KEY_LEFT:
        case 'A':
        case 'a':
            action = Left;
            break;
        case KEY_RIGHT:
        case 'D':
        case 'd':
            action = Right;
            break;
        case KEY_ENTER:
        case '\n':
            action = Start;
            break;
        case 'Q':
        case 'q':
            action = Terminate;
            break;
        case 'P':
        case 'p':
            action = Pause;
            break;
        case 32:  // Код клавиши пробела
            action = Action;
            break;
        default:
            action = NONE;
            break;
    }

    if (action != NONE) {
        int nextKey = getch(); 

        if (nextKey == key) {
            *keyHold = true; 
        }
    }

    return action;
}