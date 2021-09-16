#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

// Window dimensions
static const int width = 800;
static const int height = 600;

int main()
{
    if (SDL_Init(SDL_INIT_EVENTS) != 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

    // Create an SDL window
    SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (window == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

	bool quit = false;
	SDL_Event event;
	while(!quit){
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		SDL_Delay(1);
	}

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return (0);
}