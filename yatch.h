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

#define PROJECT_NAME "Yatch!"
#define PROJECT_VERSION 0.0.1

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 22
#define VISIBLE_HEIGHT 20
#define OFFSET (FIELD_HEIGHT - VISIBLE_HEIGHT)

#define LEFT -1
#define RIGHT 1
#define CLOCKWISE 1
#define COUNTERCLOCKWISE 3

typedef char Tetramino[4][4];
typedef char Field[FIELD_HEIGHT][FIELD_WIDTH];

typedef struct {
       int blocktype;
       int posx, posy;
       int orient;
} Block;

int random_block();
int move_piece(Field *field, Block *block, int direction);
int move_down(Field *field, Block *block);
void rotate_piece(Field *field, Block *block, int direction);
void drop_piece(Field *field, Block *block);
void put_piece(Field *field, Block *block);
int is_obstructed(Field *field, Block *block);

Block get_ghost_piece(Field *field, Block *block);

int check_field(Field *field);
void clean_field(Field *field);

void draw(Field *field, Block *block, Block *next, Block *hold, int points);

void create_block(Block *block, int piece);

extern Tetramino *blocks[7];

int Init();

#endif
