#CFLAG=-Werror -Wextra -Wall
CSTD=-std=c11 -D_XOPEN_SOURCE=700

OBJECT_FILE=game_state_init.o game_state_remove.o GameInfoData/game_info_data.o \
	user_input.o GameLogic/spawn.o GameLogic/start.o GameLogic/moving.o GameLogic/attaching.o



%.o : %.c
	@gcc $(CFLAG) $(CSTD) -c $< -o $@

tetris.a : $(OBJECT_FILE)
	@ar rcs libtetris.a $(OBJECT_FILE)

build : tetris.a object_file_clean

rebuild : 
	@make lib_clean -s
	@make build -s

lib_clean : object_file_clean
	@rm -f *.a

object_file_clean : 
	@rm -rf *.o 
	@rm -rf GameInfoData/*.o
	@rm -rf GameLogic/*.o 






GCOVFLAG=-fprofile-arcs -ftest-coverage

GCOV_OBJECT_FILE = $(OBJECT_FILE:.o=_gcov.o)

%_gcov.o : %.c
	@gcc $(CFLAG) $(GCOVFLAG) $(CSTD) -c $< -o $@

gcov_build : $(GCOV_OBJECT_FILE)
	@ar rcs libtetris.a $(GCOV_OBJECT_FILE)

gcov_rebuild : 
	@make lib_clean -s
	@make gcov_file_clean -s
	@make gcov_build -s
	@make object_file_clean -s
	
gcov_file_clean :
	@rm -rf *.gcda *.gcno 
	@rm -rf GameInfoData/*.gcda GameInfoData/*.gcno GameLogic/*.gcda GameLogic/*.gcno


clean : lib_clean gcov_file_clean




info :
	@echo "Основные цели Makefile:"
	@echo "\033[33m tetris.a \033[0m - собирает статическую библиотеку"
	@echo "\033[33m build\033[0m - собирает статическую библиотеку и удаляет объектные файлы"
	@echo "\033[33m clean \033[0m - удаляет статическую библиотеку и объектные файлы"
	@echo "\033[33m rebuild\033[0m - выполняет clean, а за ним build"
