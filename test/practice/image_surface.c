#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

SDL_Window *window;
SDL_Surface *windowSurface;

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

    window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (window == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

	windowSurface = SDL_GetWindowSurface(window);

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
    SDL_DestroyWindow(window);
	IMG_Quit();
    SDL_Quit();
}

SDL_Surface *loadImage(const char *file){
	SDL_Surface *surface;
	SDL_Surface *optimizedSurface;

	surface = IMG_Load(file);
	if (surface == NULL)
	{
		printf("fail to read %s\n", file);
		return NULL;
	}
	
	optimizedSurface = SDL_ConvertSurface(surface, windowSurface->format, 0);
	if (optimizedSurface == NULL)
	{
		printf("unable to optimize image %s\n", file);
		return NULL;
	}
	SDL_FreeSurface(surface);

	return optimizedSurface;
}

int main(int argc,char **argv){
	initAll();

	SDL_Surface *image;
	image = loadImage("image.png");

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

		SDL_Rect Rect;
		Rect.x = width / 2;
		Rect.y = height / 2;
		SDL_BlitSurface(image, NULL, windowSurface, &Rect);
		SDL_UpdateWindowSurface(window);
	}

	SDL_FreeSurface(image);

	closeAll();
	return 0;
}