/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * COPYING or http://www.wtfpl.net/ for more details. */

#ifndef PLAYER_H
#define PLAYER_H

void initPlayerPos(SDL_Rect *pos,int x,int y,int w,int h);
int playerEdgeColl(SDL_Rect *col,int screenW,int screenH,int *score);
int playerBoxColl();

#endif
