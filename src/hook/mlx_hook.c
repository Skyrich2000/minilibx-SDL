#include "mlx.h"
#include "include/mlx_int.h"
#include "include/mlx_event.h"

int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
{
    t_win_list  *win;

    GUARD (win_ptr != NULL) else { RETURN("Invalid window pointer") }
    GUARD (x_event < MLX_MAX_EVENT) else { RETURN("Wrong event") }

    win = (t_win_list *)win_ptr;
    win->hooks[x_event].hook = funct;
    win->hooks[x_event].param = param;
    return (OK);
}