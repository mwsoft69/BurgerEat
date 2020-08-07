#include <SDL.h>
#include <SDL_image.h>

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "player.h"

void initPlayerPos(SDL_Rect *pos,int x,int y,int w,int h)
{
		pos->x=x;
		pos->y=y;
		pos->w=w;
		pos->h=h;
}

/**/

int playerEdgeColl(SDL_Rect *col,int screenW,int screenH)
{
	/*Check if we went too far up or down. Y axis*/

	if((col->y < 0))
	{
		//col->y = col->y + 10;
	}

	if (col->y + col->h > screenH)
	{
		//col->y -= 10;
		printf("Bottom\n");
	}

	/*Check if we went too far left or right. X axis*/

}


void playerBoxColl(SDL_Rect *playerR,SDL_Rect *colR,int *score,int inc)
{
		/*Sides of rects*/
		int leftP,leftNPC;
		int rightP,rightNPC;
		int topP,topNPC;
		int bottomP,bottomNPC;

		/*Calc player sides*/
		leftP = playerR->x;
		rightP = playerR->x + playerR->x;
		topP = playerR->y;
		bottomP = playerR->y + playerR->h;

		/*Calc NPC sides*/
		leftNPC = colR->x;
		rightNPC = colR->x + colR->x;
		topNPC = colR->y;
		bottomNPC = colR->y + colR->h;

		/*Check collsion and update score.*/

		/*top*/
		if(topP >= bottomNPC)
		{
			*score = *score + 10;
			printf("Player Score is %d\n",*score);
			//playerR->y +=10;

		}

	if( topP >= bottomNPC )
    {
    		*score = *score + 10;
			//printf("Player Score is %d\n",*score);
			//playerR->y +=10;

    }

    if( rightP <= leftNPC )
    {
    		*score = *score + 10;
			printf("Player Score is %d\n",*score);
		//	playerR->y +=10;

    }

    if( leftP >= rightNPC )
    {
		*score = *score + 10;
		printf("Player Score is %d\n",*score);
		//playerR->y +=10;

    }
}
