#include <SDL.h>
#include <SDL_image.h>

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "npc.h"

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
