/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * COPYING or http://www.wtfpl.net/ for more details. */
 
 
#include <SDL.h>
#include <SDL_image.h>

#include "image.h"

int loadBmp(SDL_Surface **i, const char *file)
{
	*i = SDL_LoadBMP(file);
	if(!*i)
	{
		SDL_ShowSimpleMessageBox(0,"Failed to load bmp",file,0);
		SDL_FreeSurface(*i);
		*i = NULL;
		return 1;
	}

	return 0;
}


int loadPNG(SDL_Surface **i,const char *file)
{
	*i = IMG_Load(file);
	if(!i)
	{
		SDL_ShowSimpleMessageBox(0,"Failed to load png",file,0);
		SDL_FreeSurface(*i);
		*i = NULL;
		return 1;
	}
	
	return 0;
}

int convertToTexture(SDL_Texture **t,SDL_Renderer *r,SDL_Surface *s)
{
	*t = SDL_CreateTextureFromSurface(r,s);

	if(!*t)
	{
		SDL_ShowSimpleMessageBox(0,"ERROR!","Failed to convert bmp to texture",0);
		SDL_DestroyTexture(*t);
		*t = NULL;
		SDL_FreeSurface(s);
		s = NULL;
		
		return 1;
	}
	
	return 0;
}


int initIMG()
{
	/*Initlise PNG loading with SDL2_Img.*/
	
	int flags = IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	
	if((initted&flags) != flags)
	{
		printf("Error\n");
	}
}
