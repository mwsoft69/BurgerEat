#include <SDL.h>
#include <SDL_image.h>

#include <stdlib.h>


#include "init.h"

/*Prob not the best way but its public domain. let me know a better way !! :)*/
int initWindow(SDL_Window **s,const char *title, int xpos, int ypos, int h, int w)
{
	*s = SDL_CreateWindow(title,xpos,ypos,w,h,0);

	if(!*s)
	{
		SDL_ShowSimpleMessageBox(0,"ERROR!!","Failed to init window",0);
		SDL_DestroyWindow(s);
		s= NULL;
		SDL_Quit();
		exit(EXIT_FAILURE);
	}


}

