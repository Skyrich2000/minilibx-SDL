#include "mlx.h"
#include "include/mlx_int.h"
#include "include/mlx_event.h"
#include "include/mlx_keycode.h"

static int sdl_to_mlx(int sdl_keycode)
{
    switch (sdl_keycode)
    {
        case SDLK_a:
            return (KEY_A);
        case SDLK_b:
            return (KEY_B);
        case SDLK_c:
            return (KEY_C);
        case SDLK_d:
            return (KEY_D);
        default:
            return (-1);
    }
}

void    mlx_key_press_handler(t_xvar *mlx, int win_id, int sdl_keycode)
{
    t_win_list  *win;
    t_event     *ev;

    GUARD (mlx != NULL) else { return ; }

    win = mlx->win_id[win_id];
    GUARD (win != NULL) else { return ; }
    
    ev = &win->hooks[KeyPress];
    if (ev->hook)
        ev->hook(sdl_to_mlx(sdl_keycode), ev->param);
}

void    mlx_key_release_handler(t_xvar *mlx, int win_id, int sdl_keycode)
{
    t_win_list  *win;
    t_event     *ev;

    GUARD (mlx != NULL) else { return ; }

    win = mlx->win_id[win_id];
    GUARD (win != NULL) else { return ; }

    ev = &win->hooks[KeyRelease];
    if (ev->hook)
        ev->hook(sdl_to_mlx(sdl_keycode), ev->param);
}