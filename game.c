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
#include <string.h>

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


int random_block() {
    static int queue[4] = {-1, -1, -1, -1};
    int current;
    int i, j;

    if(queue[0] == -1) {
        queue[0] = rand() % 7;
        queue[1] = rand() % 7;
        queue[2] = rand() % 7;
        queue[3] = rand() % 7;
    }

    current = queue[0];

    for(i = 0; i < 4; ++i) {
        queue[i] = queue[i+1];
    }

    queue[3] = rand() % 7;
    for(j = 0; j < 4; ++j) {
        for(i = 0; i < 3; ++i) {
            if(queue[i] == queue[3]) {
                queue[3] = rand() % 7;
                break;
            }
        }
    }

    return current;
}

void lock_piece(FIELD *field, BLOCK *block) {
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            (*field)[i + block->posy][j + block->posx] |=
                blocks[block->blocktype][block->orient][i][j];
        }
    }
}

int update_field(FIELD *field) {
    int i, j, k;
    int lines = 0;
    int is_full_line;

    for (i = 0; i < FIELDHEIGHT; ++i) {
        is_full_line = 1;
        for (j = 0; j < FIELDWIDTH; ++j) {
            if(!(*field)[i][j]){
                is_full_line = 0;
                break;
            }
        }

        if(is_full_line) {
            lines++;
            for (k = i; k > 0; --k) {
                for (j = 0; j < FIELDWIDTH; ++j) {
                    (*field)[k][j] = (*field)[k-1][j];
                }
            }
        }
    }
    return lines;
}

int is_obstructed(FIELD *field, BLOCK *block) {
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if ((blocks[block->blocktype][block->orient][i][j])
                    &&  (i + block->posy > (FIELDHEIGHT - 1)
                        || j + block->posx < 0
                        || j + block->posx > (FIELDWIDTH - 1)
                        || (*field)[block->posy + i][block->posx + j])) {
                return 1;
            }
        }
    }
    return 0;
}

void create_block(BLOCK *block, int piece) {
    block->posx = (FIELDWIDTH - 4)/2;
    block->posy = OFFSET;
    block->blocktype = piece;
    block->orient = 0;
}

void clean_field(FIELD *field) {
    memset(field, 0, FIELDHEIGHT * FIELDWIDTH);
}

BLOCK get_ghost_piece(FIELD *field, BLOCK *block){
    BLOCK tempblock = *block;

    while(!is_obstructed(field, &tempblock)) {
        tempblock.posy++;
    }
    tempblock.posy--;

    return tempblock;
}

void drop_piece(FIELD *field, BLOCK *block) {
    *block = get_ghost_piece(field, block);
}

int move_down(FIELD *field, BLOCK *block){
    BLOCK tempblock = *block;
    tempblock.posy++;

    if(is_obstructed(field, &tempblock)){
        return -1;
    }

    *block = tempblock;
    return 0;
}

int move_piece(FIELD *field, BLOCK *block, int direction){
    BLOCK tempblock = *block;
    tempblock.posx += direction;

    if (is_obstructed(field, &tempblock)) {
        return 0;
    }

    *block = tempblock;
    return -1;
}

void rotate_piece (FIELD *field, BLOCK *block, int direction) {
    BLOCK tempblock = *block;
    tempblock.orient = (tempblock.orient + direction) % 4;

    if (is_obstructed(field, &tempblock)) {
        if (!move_piece(field, &tempblock, RIGHT)
                && !move_piece(field, &tempblock, LEFT)) {
            return;
        }
    }

    *block = tempblock;
}

void hold_piece(BLOCK *block, BLOCK *hold, BLOCK *next) {
    BLOCK tempblock = *block;
    int temp = block->blocktype;

    if(hold->blocktype != -1) {
        tempblock = *hold;
    } else {
        tempblock = *next;
        create_block(next, random_block());
    }

    create_block(hold, temp);
    *block = tempblock;
}

