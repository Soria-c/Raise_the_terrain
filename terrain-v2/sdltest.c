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
	double i = 0.0;
	double x = 0.0, y = 0.0, xcr, ycr, x2crf, y2crf, offx2, offy2;

	double x0 = 500, y0 = 120;
	double m = 2.0 / 5.0; /**slope**/
	double lenght = 240.0;
	double offset = 30.0;
	double lines = 8;

	xcr = xcoor(lenght, x0, m);
	ycr = ycoor(m, y0, xcr - x0);
	
	x2crf = xcoor(lenght / (lines - 1), x0, m);
	y2crf = ycoor(m, y0, x2crf - x0);
	offx2 = x2crf - x0;
	offy2 = y2crf - y0;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for(; i < offset * lines; i += offset, x += offx2, y += offy2)
	{
		SDL_RenderDrawLineF(instance.renderer, x0 - i, y0 + i, xcr - i, ycr + i);
		SDL_RenderDrawLineF(instance.renderer, x0 + x, y0 + y, x0 - (offset * (lines - 1)) + x, y0 + (offset * (lines - 1)) + y);
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
