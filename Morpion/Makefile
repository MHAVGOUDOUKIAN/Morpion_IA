all: morpion board.o game.o ia.o uvu.o

game.o: game.c game.h
	gcc -c game.c

board.o: board.c board.h
	gcc -c board.c

uvu.o: uvu.c uvu.h
	gcc -c uvu.c

ia.o: ia.c ia.h
	gcc -c ia.c

morpion: main.c board.c game.c uvu.c ia.c board.h game.h uvu.h ia.h
	gcc -g -o morpion main.c board.c game.c uvu.c ia.c