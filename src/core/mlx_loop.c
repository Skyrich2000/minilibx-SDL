#include "mlx.h"
#include "include/mlx_int.h"
#include "include/mlx_event.h"

static void render(t_xvar *mlx)
{
    t_win_list *win;

    win = mlx->win_list->next;
    while (win != NULL)
    {
        SDL_UpdateWindowSurface(win->window);
        win = win->next;
    }
}

int	mlx_loop(void *mlx_ptr)
{
    t_xvar      *mlx;
	SDL_Event   event;

    mlx = (t_xvar *)mlx_ptr;
	while (1) {
        while (SDL_PollEvent(&event)) {
			switch(event.type) {
                case SDL_WINDOWEVENT:
                    switch (event.window.event) {
                        case SDL_WINDOWEVENT_CLOSE:
                            mlx_destroy_window(mlx, mlx->win_id[event.window.windowID]);
                            break;
                    }
                    break;
                case SDL_KEYDOWN:
                    mlx_key_press_handler(mlx, event.key.windowID, event.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    mlx_key_release_handler(mlx, event.key.windowID, event.key.keysym.sym);
                    break;
			}
		}
        render(mlx);
        if (mlx->loop_hook)
            mlx->loop_hook(mlx->loop_param);
	}
    return (1);
}