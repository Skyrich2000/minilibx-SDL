#include "mlx.h"
#include "include/mlx_int.h"

// TODO: free window
static void free_win_list(t_win_list *win)
{
    if (win->next)
        free_win_list(win->next);
    free(win);
}

void	mlx_free(t_xvar *mlx)
{
    free_win_list(mlx->win_list);
    free(mlx);
    SDL_Quit();
}