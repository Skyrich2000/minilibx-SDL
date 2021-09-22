#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Window *window2;
SDL_Renderer *renderer;
SDL_Renderer *renderer2;

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
    window = SDL_CreateWindow("Hello World 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (window == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }
    printf("window %d created\n", SDL_GetWindowID(window));

    window2 = SDL_CreateWindow("Hello World 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (window == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }
    printf("window %d created\n", SDL_GetWindowID(window2));

    // Create a renderer (accelerated and in sync with the display refresh rate)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }

    renderer2 = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }
    return (1);
}

static void closeAll()
{
    SDL_DestroyRenderer(renderer2);
    SDL_DestroyWindow(window2);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main()
{
    initAll();

	bool quit = false;
	SDL_Event event;
	while(!quit){
		while(SDL_PollEvent(&event)){
			switch(event.type){
            case SDL_KEYDOWN:
                printf("window %d : %d press!\n", event.key.windowID, event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                printf("window %d : %d release!\n", event.key.windowID, event.key.keysym.sym);
                break;
			}
		}
		SDL_Delay(1);
	}

    // while(SDL_PollEvent(&event)){
    //     switch(event.type){
    //         case SDL_WINDOWEVENT:
    //             switch(event.window.event){
    //                 case SDL_WINDOWEVENT_CLOSE: {
    //                     for(int i=0;i<4;i++){
    //                         if(SDL_GetWindowID(window[i]) == event.window.windowID){ 
    //                             SDL_DestroyRenderer(renderer[i]); 
    //                             SDL_DestroyWindow(window[i]); 
    //                             break; 
    //                         } 
    //                     }
    //                 }
    //                 break;
    //             }
    //             break;
    //     } 
    // }

    closeAll();
    return (0);
}