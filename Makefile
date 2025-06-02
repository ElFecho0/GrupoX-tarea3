CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o modules/processor.o modules/validator.o modules/sorter.o
DEPS = modules/processor.h modules/validator.h modules/sorter.h

tarea3: $(OBJ)
	$(CC) $(CFLAGS) -o tarea3 $(OBJ)

main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c main.c

modules/processor.o: modules/processor.c modules/processor.h
	$(CC) $(CFLAGS) -c modules/processor.c -o modules/processor.o

modules/validator.o: modules/validator.c modules/validator.h
	$(CC) $(CFLAGS) -c modules/validator.c -o modules/validator.o

modules/sorter.o: modules/sorter.c modules/sorter.h
	$(CC) $(CFLAGS) -c modules/sorter.c -o modules/sorter.o

clean:
	rm -f *.o modules/*.o tarea3
