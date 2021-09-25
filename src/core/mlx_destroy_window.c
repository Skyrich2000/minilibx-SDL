#include "mlx.h"
#include "include/mlx_int.h"

static char *mlx_error;

static int del_window_list(t_xvar *mlx, t_win_list *win)
{
    t_win_list  *node;

    node = mlx->win_list;
    while (node != NULL)
    {
        if (node->next == win)
            break;
        node = node->next;
    }

    GUARD (node != NULL) else { THROW("Windows not found"); }
    node->next = node->next->next;
    mlx->win_id[win->id] = NULL;
    mlx->win_count--;
    free(win);
    return (OK);
}

int	mlx_destroy_window(void *mlx_ptr, void *win_ptr)
{
    t_xvar      *mlx;
    t_win_list  *win;

    GUARD (mlx_ptr != NULL) else { RETURN("Invalid mlx pointer"); }
    GUARD (win_ptr != NULL) else { RETURN("Invalid window pointer"); }

    mlx = (t_xvar *)mlx_ptr;
    win = (t_win_list *)win_ptr;

    GUARD (win_ptr != NULL) else { RETURN("Wrong window pointer"); }
    SDL_DestroyWindow(win->window);
    
    GUARD (del_window_list(mlx, win) != ERROR) else { RETURN(mlx_error); }
    return (OK);
}