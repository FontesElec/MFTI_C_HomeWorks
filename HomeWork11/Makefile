all: temp_data

temp_data: main.o temp_api.o storage.o
	gcc -o temp_data main.o temp_api.o storage.o

main.o: main.c temp_api.h
	gcc -c -o main.o main.c

temp_api.o: temp_api.c storage.h
	gcc -c -o temp_api.o temp_api.c

storage.o: storage.c
	gcc -c -o storage.o storage.c

clean:
	rm -rf *.o temp_data

