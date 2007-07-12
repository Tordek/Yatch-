SDL_CONFIG=sdl-config
CFLAGS+=`$(SDL_CONFIG) --cflags` -Wall
LFLAGS+=`$(SDL_CONFIG) --libs` -lSDL_ttf -Wall

EXTRACFLAGS+= -pg

yatch: main.o draw.o
	$(CC) main.o draw.o -o $@ $(LFLAGS)

main: main.c tetris.h
	$(CC) $@.c $(CFLAGS) -c

draw: draw.c
	$(CC) $@.c $(CFLAGS) -c
