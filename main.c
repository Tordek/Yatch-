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

int singleplayer(){
    FIELD field;
    BLOCK block, hold, next;
    SDL_Event keyevent;
    int playing = 1, level = 1, key, temp, score = 0, lines = 0, can_hold = 1, solidify;
    Uint32 speed = 800, timer;

    srand(time(NULL));

    if(!Init())
        return 1;

    timer = SDL_GetTicks() + speed;

    clean_field(&field);

    create_block(&next, random_block());
    create_block(&block, random_block());
    create_block(&hold, -1);

    draw(&field, &block, &next, &hold, score);

    while(playing) {
        key = 0;
        solidify = 0;
        while (!key) {
            if(timer < SDL_GetTicks()) {
                key = SDLK_DOWN;
            } else if(SDL_PollEvent(&keyevent) && keyevent.type == SDL_KEYDOWN) {
                key = keyevent.key.keysym.sym;
            }
        }
        if (key) {
            switch(key) {
            case SDLK_ESCAPE:
                key = 0;
                break;

            case SDLK_w:
                if(can_hold) {
                    hold_piece(&block, &hold, &next);
                    can_hold = 0;
                }
                break;

            case SDLK_LEFT:
                move_piece(&field, &block, LEFT);
                break;
           case SDLK_RIGHT:
                move_piece(&field, &block,  RIGHT);
                break;

            case SDLK_a:
                rotate_piece(&field, &block, COUNTERCLOCKWISE);
                break;

            case SDLK_s:
                rotate_piece(&field, &block,  CLOCKWISE);
                break;

            case SDLK_DOWN:
                timer = SDL_GetTicks() + speed;
                if(move_down(&field, &block) == -1) {
                    solidify = 1;
                }
                break;

            case SDLK_UP:
                timer = SDL_GetTicks() + speed;
                drop_piece(&field, &block);
                solidify = 1;
                break;

            default:
                continue;
            }

            if(solidify) {
                lock_piece(&field, &block);
                block = next;
                create_block(&next, random_block());

                temp = update_field(&field);
                score += temp * temp;
                lines += temp;
                can_hold = 1;

                if(lines > level * 10){
                    ++level;
                    speed -= 18;
                }

                if(is_obstructed(&field, &next)) {
                    playing = 0;
                    break;
                }
            }
            draw(&field, &block, &next, &hold, score);
        }
    }
    return score;
}


int main() {
	printf("%d\n",singleplayer());
	return 0;
}
