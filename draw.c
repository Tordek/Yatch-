/* Copyright 2007 Guillermo Freschi
 *
 *     This file is part of Yatch! - Yet Another Tetris Clone, Huh?.
 *
 *    Yatch! is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Yatch! is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "yatch.h"
#include "SDL.h"
#include "SDL_ttf.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

SDL_Surface *screen, *fondo, *blockpicture[18];
TTF_Font *fuente;
SDL_Rect src, dest;

void paintpiece(int x, int y, int color);

int InitVideo(Uint32 flags) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return 0;
	}

	atexit(SDL_Quit);

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16, flags);
	if (screen == NULL) {
		fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
		return 0;
	}

	return 1;
}

int InitTTF() {
	if (TTF_Init() == -1) {
		  printf("Unable to initialize SDL_ttf: %s \n", TTF_GetError());
		  return 0;
	}

	fuente = TTF_OpenFont("font.ttf", 16);
	if (fuente == NULL){
		printf("Unable to load font: %s %s \n", "font.ttf", TTF_GetError());
		return 0;
	}
	return 1;
}

int Init(){
	if(!InitVideo(SDL_DOUBLEBUF | SDL_ANYFORMAT)) {
		return 0;
	}
	if(!InitTTF()) {
		return 0;
	}

	int i;
	char name[20];
	SDL_Surface *temp;

	for(i = 0; i < 7; ++i) {
		sprintf(name, "images/bloque%d.bmp", i);
		temp = SDL_LoadBMP(name);
		if (temp == NULL) {
			printf("Unable to load bitmap: %s\n", SDL_GetError());
			return 0;
		}
		blockpicture[i] = SDL_DisplayFormat(temp);
		SDL_SetAlpha(temp,SDL_SRCALPHA,128);
		blockpicture[i+10] = SDL_DisplayFormat(temp);
	}

	temp = SDL_LoadBMP("images/bloque7.bmp");
	if (temp == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 0;
	}
	blockpicture[i] = SDL_DisplayFormat(temp);

	temp = SDL_LoadBMP("images/fondo.bmp");
	if (temp == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 0;
	}

	fondo = SDL_DisplayFormat(temp);

	SDL_FreeSurface(temp);

	src.x = 0;
	src.y = 0;
	src.w = blockpicture[1]->w;
	src.h = blockpicture[1]->h;

	dest.w = blockpicture[1]->w;
	dest.h = blockpicture[1]->h;

	return 1;
}

void draw(FIELD *field, BLOCK *block, BLOCK *next, BLOCK *hold, int score) {
	int i, j;
	SDL_Rect src, dest;
	SDL_Surface *imgtexto;
	char texto[100];

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	src.x = 0;
	src.y = 0;
	src.w = fondo->w;
	src.h = fondo->h;

	dest.x = 0;
	dest.y = 0;
	dest.w = fondo->w;
	dest.h = fondo->h;

	SDL_BlitSurface(fondo, &src, screen, &dest);

	for (i = OFFSET; i < FIELDHEIGHT; ++i)
		for (j = 0; j < FIELDWIDTH; ++j)
			if((*field)[i][j])
				paintpiece(j,i - OFFSET,7);

	BLOCK tempblock = getghostpiece(field,block);

	//Draw Ghost Piece
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if(blocks[tempblock.blocktype][tempblock.orient][i][j])
				paintpiece(j + tempblock.posx, i + tempblock.posy - OFFSET, tempblock.blocktype + 10 );

	//Draw Main Piece
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if(blocks[block->blocktype][block->orient][i][j])
				paintpiece(j + block->posx, i + block->posy - OFFSET, block->blocktype );

	//Draw Next Piece
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if(blocks[next->blocktype][next->orient][i][j])
				paintpiece(j + next->posx + 10, i + next->posy + 2, next->blocktype );

	//Draw Held Piece
	if (hold->blocktype != -1) {
		for (i = 0; i < 4; ++i)
			for (j = 0; j < 4; ++j)
				if(blocks[hold->blocktype][hold->orient][i][j])
					paintpiece(j + hold->posx + 10, i + hold->posy + 7, hold->blocktype );
	}

	sprintf(texto,"Score: %d",score);

	SDL_Color color = {255, 255, 255, 0};

	imgtexto = TTF_RenderText_Blended(fuente, texto, color);

	src.w = imgtexto->w;
	src.h = imgtexto->h;

	dest.x = 180;
	dest.y = 200;
	dest.w = imgtexto->w;
	dest.h = imgtexto->h;

	SDL_BlitSurface(imgtexto, &src, screen, &dest);

	SDL_Flip(screen);
}

void paintpiece(int x, int y, int color){
	dest.x = x * (blockpicture[color]->w) + 16;
	dest.y = y * (blockpicture[color]->h);
	SDL_BlitSurface(blockpicture[color], &src, screen, &dest);
}


