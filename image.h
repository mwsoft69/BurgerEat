/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * COPYING or http://www.wtfpl.net/ for more details. */


#ifndef IMAGE_H
#define IMAGE_H

int initIMG();
int loadBmp(SDL_Surface **i, const char *file);
int loadPNG(SDL_Surface **i,const char *file);
int convertToTexture(SDL_Texture **t,SDL_Renderer *r,SDL_Surface *s);
void setBg();

#endif
