SDL_CONFIG=sdl-config
CFLAGS+=`$(SDL_CONFIG) --cflags` -Wall
LFLAGS+=`$(SDL_CONFIG) --libs` -lSDL_ttf -Wall

EXTRACFLAGS+= -pg

yatch: main.o draw.o game.o
	$(CC) main.o draw.o game.o -o $@ $(LFLAGS)

main: main.c yatch.h
	$(CC) $@.c $(CFLAGS) -c

game: game.c yatch.h
	$(CC) $@.c $(CFLAGS) -c

draw: draw.c yatch.h
	$(CC) $@.c $(CFLAGS) -c

clean:
	rm main.o draw.o game.o yatch
