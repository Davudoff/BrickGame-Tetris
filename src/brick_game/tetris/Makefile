

create_tetris.a : 
	@make -C ./source_code/ rebuild -s

run_tests : clean
	@make -C ./source_code/ rebuild -s
	@make -C ./tests/ rebuild -s
	@./tests/tetris_tests


gcov_run_test : clean
	@make -C ./source_code/ gcov_rebuild -s
	@make -C ./tests/ gcov_rebuild -s
	./tests/tetris_tests

gcov_report : gcov_run_test
	mkdir coverage
	@gcovr -r .. --html --html-details -o ./coverage/coverage_report.html

clean :
	@make -C ./source_code/ clean -s
	@make -C ./tests/ clean -s
	@rm -rf ./coverage





info :
	@echo "Основные цели Makefile:"
	@echo "\033[33m create_tetris.a \033[0m - Пересобирает статическую библиотеку ./source_code/"
	@echo "\033[33m run_tests \033[0m - Пересобирает библиотеку, пересобирает тесты и запускает их"
	@echo "\033[33m gcov_report \033[0m - Создает отчет о покрытии"
	@echo "\033[33m clean \033[0m - Удаляет все"