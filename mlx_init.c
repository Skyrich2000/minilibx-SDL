#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "mlx.h"

void    *mlx_init()
{
    if (SDL_Init(SDL_INIT_EVENTS) != 0)
    {
        fprintf(stderr, "%s\n", (SDL_GetError()));
        return (0);
    }
    return (1);
}

void    mlx_quit()
{
    SDL_Quit();
}