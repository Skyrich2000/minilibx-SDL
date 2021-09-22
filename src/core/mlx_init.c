#include "mlx.h"
#include "include/mlx_int.h"

static char *mlx_error;

static void	sigint_handler(int signo)
{
    SDL_Quit();
    exit(130);
}

static t_win_list *win_list_init()
{
    t_win_list *new_node;

    new_node = (t_win_list *)malloc(sizeof(t_win_list));
    GUARD (new_node != NULL) else { THROW("Out of memory"); }

    bzero(new_node, sizeof(*new_node));
    new_node->next = NULL;
    return (new_node);
}

void    *mlx_init()
{
    t_xvar   *mlx;

    mlx = (t_xvar *)malloc(sizeof(t_xvar));
    GUARD (mlx != NULL) else { RETURN("Out of memory"); }

    mlx->win_list = win_list_init();
    GUARD (mlx->win_list != ERROR) else {
        free(mlx);
        RETURN(mlx_error);
    }

    GUARD (signal(SIGINT, sigint_handler) != SIG_ERR) else {
        free(mlx);
        RETURN("Signal init failed");
    }

    GUARD (SDL_Init(SDL_INIT_EVENTS) == 0) else {
        free(mlx);
        RETURN(SDL_GetError());
    }

    bzero(mlx->win_id, sizeof(mlx->win_id));
    mlx->win_count = 0;
	mlx->loop_hook = NULL;
	mlx->loop_param = NULL;
    return (mlx);
}
