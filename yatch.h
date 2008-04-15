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

#define FIELDWIDTH 10
#define FIELDHEIGHT 22
#define VISIBLEHEIGHT 20
#define OFFSET (FIELDHEIGHT - VISIBLEHEIGHT)

#define LEFT -1
#define RIGHT 1
#define CLOCKWISE 1
#define COUNTERCLOCKWISE 3

typedef char TETRISBLOCK[4][4];
typedef char FIELD[FIELDHEIGHT][FIELDWIDTH];

typedef struct {
       int blocktype;
       int posx, posy;
       int orient;
} BLOCK;

int random_block();
int move_piece(FIELD *field, BLOCK *block, int direction);
int move_down(FIELD *field, BLOCK *block);
void rotate_piece(FIELD *field, BLOCK *block, int direction);
void drop_piece(FIELD *field, BLOCK *block);
void put_piece(FIELD *field, BLOCK *block);
int is_obstructed(FIELD *field, BLOCK *block);

BLOCK get_ghost_piece(FIELD *field, BLOCK *block);

int check_field(FIELD *field);
void clean_field(FIELD *field);

void draw(FIELD *field, BLOCK *block, BLOCK *next, BLOCK *hold, int points);

void create_block(BLOCK *block, int piece);

extern TETRISBLOCK *blocks[7];

int Init();

#endif
