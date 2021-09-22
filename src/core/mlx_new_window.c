#include "mlx.h"
#include "include/mlx_int.h"

static char *mlx_error;

static t_win_list *win_list_append(t_xvar *mlx, t_win_list *win)
{
    t_win_list   *win_node;

    GUARD (mlx->win_list != NULL) else { THROW("Damaged mlx"); }
    GUARD (win->id < MLX_MAX_WINDOW) else { THROW("Maximum number of windows reached"); }
    GUARD (mlx->win_id[win->id] == NULL) else { THROW("Duplicated windoww ID"); }

    win_node = (t_win_list *)malloc(sizeof(t_win_list));
    GUARD (win_node != NULL) else { THROW("Out of memory"); }

    win->next = mlx->win_list->next;
    mlx->win_list->next = win;
    mlx->win_id[win->id] = win;
    mlx->win_count++;
    return (win_node);
}

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
{
    t_xvar      *mlx;
    t_win_list  *win;

    mlx = (t_xvar *)mlx_ptr;
    win = (t_win_list *)malloc(sizeof(t_win_list));
    GUARD (win != NULL) else { RETURN("Out of memory"); }

    win->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size_x, size_y, SDL_WINDOW_OPENGL);
    GUARD (win->window != NULL) else {
        free(win);
        RETURN(SDL_GetError());
    }
    
    win->id = SDL_GetWindowID(win->window);
    GUARD (win_list_append(mlx, win) != ERROR) else {
        free(win);
        SDL_DestroyWindow(win->window);
        RETURN(mlx_error);
    }

    win->surface = SDL_GetWindowSurface(win->window);
    bzero(win->hooks, sizeof(win->hooks));
    return (win);
}