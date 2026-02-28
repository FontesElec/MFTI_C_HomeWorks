all: snake

snake: src/main.o src/screen.o src/snake.o src/greetings.o src/main_menu.o src/common.o src/game.o src/game_over.o src/final.o
	gcc src/main.o src/screen.o src/snake.o src/greetings.o src/main_menu.o  src/common.o src/game.o src/game_over.o src/final.o -o snake -lncurses

src/main.o: src/main.c inc/screen.h inc/snake.h inc/common.h
	gcc -Wall -Wextra -DNCURSES_STATIC -Iinc -c src/main.c -o src/main.o 

src/screen.o: src/screen.c inc/screen.h inc/snake.h inc/common.h inc/greetings.h inc/main_menu.h inc/game.h inc/game_over.h
	gcc -Wall -Wextra -DNCURSES_STATIC -Iinc -c src/screen.c -o src/screen.o

src/greetings.o: src/greetings.c inc/greetings.h
	gcc -Wall -Wextra -DNCURSES_STATIC -Iinc -c src/greetings.c -o src/greetings.o

src/main_menu.o: src/main_menu.c inc/main_menu.h inc/common.h
	gcc -Wall -Wextra -DNCURSES_STATIC -Iinc -c src/main_menu.c -o src/main_menu.o

src/game.o: src/game.c inc/game.h inc/common.h
	gcc -Wall -Wextra -DNCURSES_STATIC -Iinc -c src/game.c -o src/game.o

src/game_over.o: src/game_over.c inc/game_over.h inc/common.h
	gcc -Wall -Wextra -DNCURSES_STATIC -Iinc -c src/game_over.c -o src/game_over.o

src/final.o: src/final.c inc/final.h inc/common.h
	gcc -Wall -Wextra -DNCURSES_STATIC -Iinc -c src/final.c -o src/final.o

src/snake.o: src/snake.c inc/snake.h inc/common.h
	gcc -Wall -Wextra -DNCURSES_STATIC -Iinc -c src/snake.c -o src/snake.o

src/common.o: src/common.c inc/common.h
	gcc -Wall -Wextra -DNCURSES_STATIC -Iinc -c src/common.c -o src/common.o

clean:
	rm -f src/*.o

rebuild: clean all

.PHONY: all clean rebuild