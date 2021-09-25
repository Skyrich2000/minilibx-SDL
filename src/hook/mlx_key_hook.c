#include "mlx.h"
#include "include/mlx_int.h"
#include "include/mlx_event.h"

int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param)
{
    t_win_list  *win;

    GUARD (win_ptr != NULL) else { RETURN("Invalid window pointer") }

    win = (t_win_list *)win_ptr;
    win->hooks[KeyPress].hook = funct_ptr;
    win->hooks[KeyPress].param = param;
    return (OK);
}