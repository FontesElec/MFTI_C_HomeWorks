.PHONY: all clean

all: square_calc

square_calc: src/main.o src/functions.o src/solving.o
	gcc -Wall -Wextra -Iinc src/main.o src/functions.o src/solving.o -o square_calc

src/main.o: src/main.c inc/solving.h
	gcc -Wall -Wextra -Iinc -c src/main.c -o src/main.o

src/functions.o: src/functions.c inc/functions.h
	gcc -Wall -Wextra -Iinc -c src/functions.c -o src/functions.o

src/solving.o: src/solving.c inc/solving.h
	gcc -Wall -Wextra -Iinc -c src/solving.c -o src/solving.o

clean:
	rm -f src/*.o square_calc