CC=g++
CFLAGS=-std=c++0x-I.
DEPS = Enemy.h, Goblin.h, Orc.h, Troll.h, GameBoard.h
OBJ = main.o Enemy.o Goblin.o Orc.o Troll.o GameBoard.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Assignment3: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

tidy:
	rm -f *.o core

clean:
	rm -f *.o core Assignment3