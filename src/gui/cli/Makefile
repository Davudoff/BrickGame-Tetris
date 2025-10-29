#CFLAG=-Werror -Wextra -Wall
CSTD=-std=c11 -D_XOPEN_SOURCE=700

OBJECT_FILE=main.o entered_key.o\
	Draw_Interface/draw_interface.o Draw_Interface/outer_frame_draw.o Draw_Interface/inner_frame_draw.o \
	Draw_Interface/frame_for_tetris_label_draw.o Draw_Interface/labels_draw.o Draw_Interface/display_game_data.o
BACK_PATH=../../brick_game/tetris/source_code/libtetris.a -I../../brick_game/tetris/source_code/ -lncursesw


%.o : %.c
	@gcc $(CFLAG) $(CSTD) -c $< -o $@

build : $(OBJECT_FILE)
	@gcc $(OBJECT_FILE) -o test.o $(BACK_PATH)
	

clean :
	@rm -rf *.o Draw_Interface/*.o

rebuild : 
	@make clean -s
	@make build -s

run : 
	@make rebuild -s
	./test.o
	