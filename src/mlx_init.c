#include "mlx.h"
#include "mlx_int.h"

void    *mlx_init()
{
    t_xvar   *xvar;

    xvar = (t_xvar *)malloc(sizeof(t_xvar));
    if (xvar == NULL)
    {
        return (0);
        exit(1);
    }
    if (SDL_Init(SDL_INIT_EVENTS) != 0)
    {
        free(xvar);
        return (0);
    }
    xvar->win_list = 0;
	xvar->loop_hook = 0;
	xvar->loop_param = 0;
    xvar->end_loop = 0;
    return (1);
}

int	mlx_loop (void *mlx_ptr)
{

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
	}
}