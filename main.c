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
	}, {
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
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			(*field)[i + block->posy][j + block->posx] |= 
				blocks[block->blocktype][block->orient][i][j];
		}
	}
}

int checkfield(FIELD *field) {
	int i, j, k, lines = 0;
	int fullline = 1;
	for (i = 0; i < FIELDHEIGHT; ++i) {
		for (j = 0; j < FIELDWIDTH; ++j) {
			if(!(*field)[i][j]){
				fullline = 0;
				break;
			}
		}
		if(fullline) {
			lines++;
			for (k = i; k > 0; --k) {
				for (j = 0; j < FIELDWIDTH; ++j) {
					(*field)[k][j] = (*field)[k-1][j];
				}
			}
		} else {
			fullline = 1;
		}
	}
	return lines;
}

int obstructed(FIELD *field, BLOCK *block) {
	int i, j;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			if ((blocks[block->blocktype][block->orient][i][j])
					&&	(i + block->posy > (FIELDHEIGHT - 1)
					   	|| j + block->posx < 0 || j + block->posx > (FIELDWIDTH - 1)
					   	|| (*field)[block->posy + i][block->posx + j])) {
				return 1;
			}
		}
	}
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
	while(!obstructed(field, &tempblock)) {
		tempblock.posy++;
	}
	tempblock.posy--;
	return tempblock;
}

void droppiece(FIELD *field, BLOCK *block) {
	BLOCK tempblock = *block;
	tempblock = getghostpiece(field, block);
	*block = tempblock;
}

int movedown(FIELD *field, BLOCK *block){
	BLOCK tempblock = *block;
	tempblock.posy++;
	if(obstructed(field, &tempblock)){
		return -1;
	}
	*block = tempblock;
	return 0;
}

void movepiece(FIELD *field, BLOCK *block, int direction){
	BLOCK tempblock = *block;
	tempblock.posx += direction;	
	if (!obstructed(field, &tempblock)) {
		*block = tempblock;
	}
}

void rotatepiece (FIELD *field, BLOCK *block, int direction) {
	BLOCK tempblock = *block;
	
	if(direction == 1) {
		tempblock.orient = (tempblock.orient + 3) % 4;
	} else {
		tempblock.orient = (tempblock.orient + 1) % 4;
	}
	
	if (!obstructed(field, &tempblock)) {
		*block = tempblock;
	}
}

void holdpiece(BLOCK *block, BLOCK *hold, BLOCK *next) {
	BLOCK tempblock = *block;
	BLOCK temp = *block;
	
	if(hold->blocktype != -1) {
		tempblock = *hold;
	} else {
		tempblock = *next;
		createblock(next, randomnum(7));
	}
	
	createblock(hold, temp.blocktype);
	*block = tempblock;
}

int singleplayer(){
	FIELD field;
	BLOCK block, hold, next;
	SDL_Event keyevent;
	int jugando = 1, nivel, tecla, temp, puntos = 0, lineas = 0, canhold = 1, solidify;
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
	
	while(jugando) {
		tecla = 0;
		solidify = 0;
		
		if(timer < SDL_GetTicks()) {
			tecla = SDLK_DOWN;
		} else if(SDL_PollEvent(&keyevent) && keyevent.type == SDL_KEYDOWN) {
			tecla = keyevent.key.keysym.sym;
		}
		
		switch(tecla) {
		case SDLK_ESCAPE:
			jugando = 0;
			break;
		
		case SDLK_w:
			if(canhold) {
				holdpiece(&block, &hold, &next);
				canhold = 0;
			}
			break;
			
		case SDLK_LEFT:
			movepiece(&field, &block, -1);
			break;
			
		case SDLK_RIGHT:
			movepiece(&field, &block,  1);
			break;
			
		case SDLK_a:
			rotatepiece(&field, &block, -1);
			break;
			
		case SDLK_s:
			rotatepiece(&field, &block,  1);
			break;
			
		case SDLK_DOWN:
			timer = SDL_GetTicks() + speed;
			if(movedown(&field, &block) == -1) {
				solidify = 1;
			}
			break;
			
		case SDLK_UP:
			timer = SDL_GetTicks() + speed;	
			droppiece(&field, &block);
			solidify = 1;
			break;
			
		default:
			break;
		}
		
		if (tecla) {
			if(solidify) {
				putpiece(&field, &block);
				block = next;
				createblock(&next, randomnum(7));
				
				temp = checkfield(&field);
				puntos += temp * temp;
				lineas += temp;
				canhold = 1;
				
				if(lineas > nivel * 10){
					++nivel;
					speed -= 18;
				}
				
				if(obstructed(&field, &next)) {
					jugando = 0;
					break;
				}
			}
			draw(&field, &block, &next, &hold, puntos);
		}
	}
	
	return puntos;
}

int main() {
	printf("%d\n",singleplayer());
	return 0;
}
