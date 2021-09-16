
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

SDL_Window *window;
SDL_Renderer *renderer;

// Window dimensions
static const int width = 800;
static const int height = 600;

static int initAll()
{
    if (SDL_Init(SDL_INIT_EVENTS) != 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

    // Create an SDL window
    window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (window == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

    // Create a renderer (accelerated and in sync with the display refresh rate)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		return (0);
	}

    return (1);
}

static void closeAll()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
	IMG_Quit();
    SDL_Quit();
}

SDL_Texture *loadTexture(const char *file){
	SDL_Surface *surface;
	SDL_Texture *texture;

	surface = IMG_Load(file);
	if (surface == NULL){
		printf("fail to read %s\n", file);
		return NULL;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL){
		printf("unable to create texture.\n");
	}
	SDL_FreeSurface(surface);

	return texture;
}

void drawTexture(SDL_Renderer *renderer,int x,int y,SDL_Texture *texture){
	SDL_Rect src;
	SDL_Rect dst;
	
	src.x = 0;
	src.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

	dst.x = x;
	dst.y = y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, texture, NULL, &dst);
}

int main(int argc,char **argv){
	initAll();

	SDL_Texture *texture;
	texture = loadTexture("image.png");

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
		SDL_RenderClear(renderer);
		drawTexture(renderer, width / 2, height / 2, texture);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);

	closeAll();
	return 0;
}	