CFLAG=-Werror -Wall -Wextra
CSTD=-std=c11 -D_XOPEN_SOURCE=700
CLIBFLAG=-lcheck -lm -lsubunit ../source_code/libtetris.a -I../source_code/

OBJECT_FILE=main.o game_state_init_test.o 



%.o : %.c
	@gcc $(CFLAG) $(CSTD) -c $< -o $@

build : $(OBJECT_FILE)
	@gcc $(OBJECT_FILE) -o tetris_tests $(CLIBFLAG)

clean : 
	@rm -f tetris_tests
	@rm -f *.o

obj_file_clean : 
	@rm -f *.o

rebuild : clean build obj_file_clean



GCOVFLAG=-fprofile-arcs -ftest-coverage

gcov_build : $(OBJECT_FILE)
	@gcc $(OBJECT_FILE) -o tetris_tests $(GCOVFLAG) $(CLIBFLAG)

gcov_rebuild : clean gcov_build


