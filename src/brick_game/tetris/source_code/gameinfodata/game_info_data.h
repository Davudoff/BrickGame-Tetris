#ifndef GAME_INFO_DATA
#define GAME_INFO_DATA

#define ON 1
#define OFF 0

#define WIDTH 10
#define HEIGHT 20


typedef struct {
    int **field;
    int **next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;


GameInfo_t updateCurrentState();

int*** get_field_ptr();
int*** get_next_ptr();
int get_score();
int get_high_score();
int get_level();
int get_speed();
int get_pause();

void set_field(int ***newField);
void set_next(int ***nextFigure);
void set_score(int val);
void set_high_score(int val);
void set_level(int val);
void set_speed(int val);
void set_pause(int val);



#endif