#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>

typedef struct SDL_instance 
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	
} SDL_Instance;

int init_instance(SDL_Instance *);

#endif 
