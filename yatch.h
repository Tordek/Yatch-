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

#ifndef _yatch_h_
#define _yatch_h_

#define PROJECTNAME "Yatch!"
#define PROJECTVERSION 0.0.1

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define FIELDWIDTH 10
#define FIELDHEIGHT 22
#define VISIBLEHEIGHT 20
#define OFFSET (FIELDHEIGHT - VISIBLEHEIGHT)

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80

typedef char TETRISBLOCK[4][4];
typedef char FIELD[FIELDHEIGHT][FIELDWIDTH];

typedef struct {
       int blocktype;
       int posx, posy;
       int orient;
} BLOCK;

int randomnum(int n);
int blockmove(FIELD *field, BLOCK *block, int direction);
int blockturn(FIELD *field, BLOCK *block);

void putpiece(FIELD *field, BLOCK *block);
int checkfield(FIELD *field);

int obstructed(FIELD *field, BLOCK *block);
void draw(FIELD *field, BLOCK *block, BLOCK *next, BLOCK *hold, int points);

void createblock(BLOCK *block, int piece);

BLOCK getghostpiece(FIELD *field, BLOCK *block);

extern TETRISBLOCK *blocks[7];

int Init();

#endif
