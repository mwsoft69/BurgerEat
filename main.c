/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * COPYING or http://www.wtfpl.net/ for more details. */

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "image.h"

/*Prob not the best way but its public domain. let me know a better way !! :)*/
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



void initPlayerPos(SDL_Rect *pos,int x,int y,int w,int h)
{
		pos->x=x;
		pos->y=y;
		pos->w=w;
		pos->h=h;
}

void initBurgerPos(SDL_Rect *bPos,int screenH,int screenW)
{
	/*Create timer.*/
	//SDL_TimerID waitTime;

	//Uint32 delay = 

	/*"Randomly" place the burger sprite. rand() and srand are fine for this*/
	
	/*Set height and width of sprite.*/
	bPos->h=64;
	bPos->w=64;

	/*seed random numbers*/
	srand(time(NULL));
	
	int wRand,hRand,dRand = 0;

	hRand = (rand()%bPos->h/screenH);
	wRand = (rand()%bPos->w/screenW);
	dRand = (rand()%5000)+1000;

	/*stuff idk if it works*/
	//SDL_Delay(dRand);
	bPos->x = wRand;
	bPos->y = hRand;


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
	SDL_Surface *npc = NULL;
	SDL_Surface *player = NULL;
	
	/*NPC texture*/
	SDL_Texture *t1;
	
	/*Player texture*/
	SDL_Texture *t2;
	
	SDL_Rect cbNpcRect;
	SDL_Rect cbPlayerRect;
	
	initPlayerPos(&cbPlayerRect,50,80,64,64);

	SDL_Init(SDL_INIT_EVERYTHING);

	initWindow(&screen,title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screenX,screenY);

	initIMG();
	
	/*Create our renderer*/
	
	ren = SDL_CreateRenderer(screen,-1,SDL_RENDERER_ACCELERATED);
	
	/*load bmp*/

	loadPNG(&npc,"art/CheeseburgerAlpha.png");
	
	loadPNG(&player,"art/CheeseburgerAlpha.png");

	convertToTexture(&t1,ren,player);
	convertToTexture(&t2,ren,npc);
	
	
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
				/*Move the player around with arrow keys.*/
				switch (e.key.keysym.sym)
				{
					case SDLK_UP:
					
					cbPlayerRect.y -= 10;
					break;
					
					case SDLK_DOWN:
					
					cbPlayerRect.y += 10;
					break;
					
					case SDLK_LEFT:
					
					cbPlayerRect.x -= 10;
					break;
					
					case SDLK_RIGHT:
					
					cbPlayerRect.x += 10;
					break;
				}
				 
			}
		}

		/*Do all drawing and logic here*/
		initBurgerPos(&cbNpcRect,screenX,screenY);
		SDL_RenderClear(ren);
		SDL_RenderCopy(ren,t2,NULL,&cbNpcRect);
		SDL_Delay(33);
		SDL_RenderCopy(ren,t1,NULL,&cbPlayerRect);
		SDL_Delay(33);
		SDL_RenderPresent(ren);
		SDL_Delay(33);
	}
	
	
	/*Free memory and quit.*/
	SDL_FreeSurface(player);
	SDL_FreeSurface(npc);
	SDL_DestroyTexture(t1);
	SDL_DestroyTexture(t2);
	endCleanup(screen,ren);
	
	quit = true;
	return 0;
}	
