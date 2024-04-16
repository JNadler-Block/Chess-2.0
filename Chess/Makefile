CC = g++
CFLAGS = -std=c++20 -Wall -g
objects = Board.o Bishop.o King.o Queen.o Pawn.o Knight.o Rook.o

default: main

main: main.o $(objects)
	$(CC) $(CFLAGS) -o main main.o $(objects)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o
	rm *.hpp.gch