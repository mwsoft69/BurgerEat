/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * COPYING or http://www.wtfpl.net/ for more details. */

#include <SDL.h>
#include <SDL_image.h>

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "image.h"
#include "npc.h"
#include "player.h"
#include "init.h"

typedef enum
{
	UP,DOWN,LEFT,RIGHT
}keyPress;

void endCleanup(SDL_Window *w,SDL_Renderer *r)
{
	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);
	SDL_Quit();
}

void movePlayer(keyPress k,SDL_Rect *r,int vol)
{
	if(k == UP)
	{
		r->y -= vol;
	}

	if(k == DOWN)
	{
	r->y += vol;
	}

	if(k==LEFT)
	{
		r->x -= vol;
	}

	if(k==RIGHT)
	{
		r->x += vol;
	}
}


int main(int argc, char ** argv)
{

	/*Define event "boolean" and SDL_Event */
	bool quit = false;
	SDL_Event  e;

	/*Players score.*/

	int *playerScore = 0;
	int vol = 10;
	/**/
	int screenW = 480;
	int screenH = 640;
	char *title ="My Awesome Game!";
	SDL_Renderer *ren = NULL;
	SDL_Window *screen = NULL;
	SDL_Surface *npc = NULL;
	SDL_Surface *player = NULL;
	SDL_Surface *bg = NULL;

	/*NPC texture*/
	SDL_Texture *t1 = NULL;

	/*Player texture*/
	SDL_Texture *t2 = NULL;

	/*Background texture.*/
	SDL_Texture *bgTexture = NULL;

	SDL_Rect cbNpcRect;
	SDL_Rect cbPlayerRect;

	initPlayerPos(&cbPlayerRect,50,80,83,59);

	SDL_Init(SDL_INIT_EVERYTHING);

	initWindow(&screen,title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screenW,screenH);

	initIMG();

	/*Create our renderer*/

	ren = SDL_CreateRenderer(screen,-1,SDL_RENDERER_ACCELERATED);

	/*load bmp*/

	loadPNG(&npc,"art/CheeseburgerAlpha.png");

	loadPNG(&player,"art/CheeseburgerAlphaCrop.png");

	loadPNG(&bg,"art/Space003.png");

	convertToTexture(&t1,ren,player);
	convertToTexture(&t2,ren,npc);
	convertToTexture(&bgTexture,ren,bg);

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

					movePlayer(UP,&cbPlayerRect,vol);
					//cbPlayerRect.y -= 10;
					break;

					case SDLK_DOWN:

					movePlayer(DOWN,&cbPlayerRect,vol);
					break;

					case SDLK_LEFT:

					movePlayer(LEFT,&cbPlayerRect,vol);
					break;

					case SDLK_RIGHT:

					movePlayer(RIGHT,&cbPlayerRect,vol);
					break;
				}

			}
			playerEdgeColl(&cbPlayerRect,screenH,screenW);
			playerBoxColl(&cbPlayerRect,&cbNpcRect,&playerScore,5);
		}

		/*Do all drawing and logic here*/

		initBurgerPos(&cbNpcRect,screenW,screenH);



		SDL_RenderClear(ren);

		/*Add delays to slow down the game and reduce CPU usage.*/

		/*Render our background.*/
		SDL_RenderCopy(ren,bgTexture,NULL,NULL);


		SDL_RenderCopy(ren,t2,NULL,&cbNpcRect);

		SDL_RenderCopy(ren,t1,NULL,&cbPlayerRect);


		SDL_RenderPresent(ren);
		SDL_Delay(33);


	}


	/*Free memory and quit.*/
	SDL_FreeSurface(player);
	SDL_FreeSurface(npc);
	SDL_DestroyTexture(t1);
	SDL_DestroyTexture(t2);
	SDL_DestroyTexture(bgTexture);
	SDL_FreeSurface(bg);
	IMG_Quit();
	endCleanup(screen,ren);


	quit = true;
	return 0;
}
