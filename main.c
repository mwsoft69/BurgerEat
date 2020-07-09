/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * COPYING or http://www.wtfpl.net/ for more details. */

#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int initWindow(SDL_Window **s,const char *title, int xpos, int ypos, int x, int y)
{
	*s = SDL_CreateWindow(title,xpos,ypos,x,y,0);
	
	if(!*s)
	{
		SDL_ShowSimpleMessageBox(0,"ERROR!!","Failed to init window",0);
		SDL_DestroyWindow(s);
		s= NULL;
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	
}

void endCleanup(SDL_Window *w,SDL_Renderer *r)
{
	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);
	SDL_Quit();
}


int  loadBmp(SDL_Surface **i, const char *file)
{
	*i = SDL_LoadBMP(file);
	if(!*i)
	{
		SDL_ShowSimpleMessageBox(0,"Failed to load bmp",file,0);
		SDL_FreeSurface(*i);
		*i = NULL;		
	}



}

void convertToTexture(SDL_Texture **t,SDL_Renderer *r,SDL_Surface *s)
{
	*t = SDL_CreateTextureFromSurface(r,s);

	if(!*t)
	{
		SDL_ShowSimpleMessageBox(0,"ERROR!","Failed to convert bmp to texture",0);
		SDL_DestroyTexture(*t);
		*t = NULL;
		SDL_FreeSurface(s);
		s = NULL;
	}
}


int main(int argc, char ** argv)
{

	/*Define event "boolean" and SDL_Event */
	bool quit = false;
	SDL_Event  e;
	int screenY = 480;
	int screenX = 640;
	char *title ="My Awesome Game!";
	SDL_Renderer *ren = NULL;
	SDL_Window *screen = NULL;
	SDL_Surface *bmp = NULL;
	SDL_Texture *t = NULL;

	SDL_Init(SDL_INIT_EVERYTHING);

	initWindow(&screen,title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screenX,screenY);

	/*Create our renderer*/
	
	ren = SDL_CreateRenderer(screen,-1,SDL_RENDERER_ACCELERATED);
	
	/*load bmp*/

	loadBmp(&bmp,"test.bmp");
	

	convertToTexture(&t,ren,bmp);
	
	
	/*Main game loop.*/
	
	while(!quit)
	{	
		/*Event loop.*/	
		while(SDL_PollEvent(&e) !=0 )
		{

			if(e.type == SDL_QUIT)
			{
				quit = true;
			}

			if(e.type == SDL_KEYDOWN)
			{
				printf("Stop that!!\n");
			}
		}

		/*Do all drawing and logic here*/
		SDL_RenderClear(ren);
		SDL_RenderCopy(ren,t,NULL,NULL);
		SDL_RenderPresent(ren);


	}
	
	SDL_FreeSurface(bmp);
	SDL_DestroyTexture(t);	
	endCleanup(screen,ren);
	quit = true;
	return 0;
}	
