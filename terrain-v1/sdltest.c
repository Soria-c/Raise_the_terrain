#include <SDL2/SDL.h>
#include "main.h"

int poll_events(void)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
			if (key.keysym.scancode == 0x29)
				return (1);
			break;
		}
	}
	return (0);
}
void draw_stuff(SDL_Instance instance)
{
	int i = 0;
	float x = 0, y = 0;
	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for(;i < 240; i += 30, x += 37.5, y += 15)
	{
		SDL_RenderDrawLineF(instance.renderer, 300 - i, 100 + i, 562.5 - i, 205 + i);
		SDL_RenderDrawLineF(instance.renderer, 300 + x, 100 + y, 90 + x, 310 + y);
	}

}

int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance))
		return (1);
	while(1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events())
			break;
		draw_stuff(instance);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}
int init_instance(SDL_Instance *instance)
{

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "zzz\n");
		return (0);
	}
	instance->window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 720, 0);
	if (!instance->window)
	{
		printf("asd2\n");
		SDL_Quit();
		return (1);
	}
	instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!instance->renderer)
	{
		SDL_DestroyWindow(instance->window);
		printf("qwe\n");
		SDL_Quit();
		return (1);
	}
	return 0;
}
