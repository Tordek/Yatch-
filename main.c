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
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "SDL.h"

TETRISBLOCK b1[4] = {
	{
		{0, 0, 0, 0}, 
		{1, 1, 1, 1}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 0, 1, 0}, 
		{0, 0, 1, 0}, 
		{0, 0, 1, 0}, 
		{0, 0, 1, 0}
	}, {
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}, 
		{1, 1, 1, 1}, 
		{0, 0, 0, 0}
	}, {
		{0, 1, 0, 0}, 
		{0, 1, 0, 0}, 
		{0, 1, 0, 0}, 
		{0, 1, 0, 0}
	}
};

TETRISBLOCK b2[4] = {
	{
		{2, 0, 0, 0}, 
		{2, 2, 2, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 2, 2, 0}, 
		{0, 2, 0, 0}, 
		{0, 2, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 0, 0, 0}, 
		{2, 2, 2, 0}, 
		{0, 0, 2, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 2, 0, 0}, 
		{0, 2, 0, 0}, 
		{2, 2, 0, 0}, 
		{0, 0, 0, 0}
	}
};

TETRISBLOCK b3[4] = {
	{
		{0, 3, 3, 0}, 
		{0, 3, 3, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 3, 3, 0}, 
		{0, 3, 3, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 3, 3, 0}, 
		{0, 3, 3, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 3, 3, 0}, 
		{0, 3, 3, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	}
};

TETRISBLOCK b4[4] = {
	{
		{0, 0, 4, 0}, 
		{4, 4, 4, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 4, 0, 0}, 
		{0, 4, 0, 0}, 
		{0, 4, 4, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 0, 0, 0}, 
		{4, 4, 4, 0}, 
		{4, 0, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{4, 4, 0, 0}, 
		{0, 4, 0, 0}, 
		{0, 4, 0, 0}, 
		{0, 0, 0, 0}
	}
};


TETRISBLOCK b5[4] = {
	{
		{0, 5, 5, 0}, 
		{5, 5, 0, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 5, 0, 0}, 
		{0, 5, 5, 0}, 
		{0, 0, 5, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 0, 0, 0}, 
		{0, 5, 5, 0}, 
		{5, 5, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{5, 0, 0, 0}, 
		{5, 5, 0, 0}, 
		{0, 5, 0, 0}, 
		{0, 0, 0, 0}
	}
};

TETRISBLOCK b6[4] = {
	{
		{0, 6, 0, 0}, 
		{6, 6, 6, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 6, 0, 0}, 
		{0, 6, 6, 0}, 
		{0, 6, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 0, 0, 0}, 
		{6, 6, 6, 0}, 
		{0, 6, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 6, 0, 0}, 
		{6, 6, 0, 0}, 
		{0, 6, 0, 0}, 
		{0, 0, 0, 0}
	}
};

TETRISBLOCK b7[4] = {
	{
		{7, 7, 0, 0}, 
		{0, 7, 7, 0}, 
		{0, 0, 0, 0}, 
		{0, 0, 0, 0}
	},{
		{0, 0, 7, 0}, 
		{0, 7, 7, 0}, 
		{0, 7, 0, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 0, 0, 0}, 
		{7, 7, 0, 0}, 
		{0, 7, 7, 0}, 
		{0, 0, 0, 0}
	}, {
		{0, 7, 0, 0}, 
		{7, 7, 0, 0}, 
		{7, 0, 0, 0}, 
		{0, 0, 0, 0}
	}
};

TETRISBLOCK *blocks[7] = { b1, b2, b3, b4, b5, b6, b7 };

int randomnum(int n) {
	return (int) ((float) n * rand () / (RAND_MAX));
}

void putpiece(FIELD *field, BLOCK *block) {
	int i, j;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			(*field)[i + block->posy][j + block->posx] |= 
				blocks[block->blocktype][block->orient][i][j];
}

//Cleans completed lines and returns how many it removed, and -1.
//Might be doing too much.
int checkfield(FIELD *field) {
	int i, j, k, lines = 0;
	int fullline = 1;
	for (i = 0; i < FIELDHEIGHT; ++i) {
		for (j = 0; j < FIELDWIDTH; ++j)
			if(!(*field)[i][j]){
				fullline = 0;
				break;
			}
		if(fullline) {
			lines++;
			for (k = i; k > 0; --k)
				for (j = 0; j < FIELDWIDTH; ++j)
					(*field)[k][j] = (*field)[k-1][j];
		} else
			fullline = 1;
	}
	for (i = 0; i < FIELDWIDTH; ++i)
		if ((*field)[OFFSET][i])
			return -1;
	return lines;
}

int obstructed(FIELD *field, BLOCK *block) {
	int i, j;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if ((blocks[block->blocktype][block->orient][i][j])
					&&	(i + block->posy > (FIELDHEIGHT - 1)
					   	|| j + block->posx < 0 || j + block->posx > (FIELDWIDTH - 1)
					   	|| (*field)[block->posy + i][block->posx + j]))
				return 1;
	return 0;
}

void createblock(BLOCK *block, int piece) {
	block->posx = (FIELDWIDTH - 4)/2;
	block->posy = OFFSET;
	block->blocktype = piece;
	block->orient = 0;
}

void cleanfield(FIELD *field) {
	memset(field, 0, FIELDHEIGHT * FIELDWIDTH);
}

BLOCK getghostpiece(FIELD *field, BLOCK *block){
	BLOCK tempblock = *block;
	while(!obstructed(field,&tempblock))
		tempblock.posy++;
	tempblock.posy--;
	return tempblock;
}

int movepiece(FIELD *field, BLOCK *block, BLOCK *hold, BLOCK *next, int tecla){
	int nextblock=0;
	static int canhold=1;
	BLOCK tempblock = *block;

	switch(tecla) {
		case SDLK_w:
			if(canhold) {
				BLOCK temp = *block;
				if(hold->blocktype != -1) {
					tempblock = *hold;
				} else {
					tempblock = *next;
					createblock(next, randomnum(7));
				}
				createblock(hold, temp.blocktype);
				canhold = 0;
			}
			break;

		case SDLK_UP:
			tempblock = getghostpiece(field,block);
			putpiece(field,&tempblock);
			nextblock = 1;
			break;

		case SDLK_DOWN:
			tempblock.posy++;
			if(obstructed(field,&tempblock)){
				putpiece(field,block);
				nextblock = 1;
			}
			break;

		case SDLK_LEFT:
			tempblock.posx--;
			break;

		case SDLK_RIGHT:
			tempblock.posx++;
			break;

		case SDLK_a:
			tempblock.orient = (tempblock.orient + 3) % 4;
			break;

		case SDLK_s:
			tempblock.orient = (tempblock.orient + 1) % 4;
			break;

		default:
			break;
	}
	
	
	if (!obstructed(field, &tempblock)) {
		*block = tempblock;
	} else if(nextblock){
		*block = *next;
		createblock(next, randomnum(7));
		canhold = 1;
	} else 

	if(obstructed(field, next))
		return -1;

	return checkfield(field);
}

int singleplayer(){
	FIELD field;
	BLOCK block, hold, next;
	SDL_Event keyevent;
	int jugando=1, nivel, tecla, temp, puntos=0, lineas=0;
	Uint32 speed=800, timer;

	srand (time (NULL));

	if(!Init())
		return 1;
	
	timer = SDL_GetTicks() + speed;

	cleanfield(&field);

	createblock(&next, randomnum(7));
	createblock(&block, randomnum(7));
	createblock(&hold, -1);

	draw(&field, &block, &next, &hold, puntos);
	while(jugando){
		while(SDL_PollEvent(&keyevent)) {
			if(keyevent.type == SDL_KEYDOWN) {
				tecla = keyevent.key.keysym.sym;
				if(tecla == SDLK_p) {
					return 0;
				}
				if((temp  = movepiece(&field, &block, &hold, &next, tecla)) == -1)
					return 0;
				if(tecla == SDLK_UP || tecla == SDLK_DOWN)
					timer = SDL_GetTicks() + speed;
				puntos += temp*temp;
				lineas += temp;
				if(lineas > nivel*10){
					++nivel;
					speed-=18;
				}
				draw(&field, &block, &next, &hold, puntos);
			}
		}
		if(timer < SDL_GetTicks()){
			if(movepiece(&field, &block, &hold, &next, SDLK_DOWN) == -1)
				return 0;
			draw(&field, &block, &next, &hold, puntos);
			timer = SDL_GetTicks() + speed;
		}
	}
	return 0;
}

int multiplayer(){

}
int main() {
	singleplayer();
	return 0;
}
