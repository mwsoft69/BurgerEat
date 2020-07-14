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

int playerEdgeColl(SDL_Rect *col,int screenW,int screenH,int *score)
{
	/*Check if we went too far up or down. Y axis*/

	if((col->y < 0))
	{
		col->y = col->y + 10;
		*score +=1;
	}

	if (col->y + col->h > screenH)
	{
		col->y -= 10;
		printf("Bottom\n");
	}

	/*Check if we went too far left or right. X axis*/

}
