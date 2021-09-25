#include "mlx.h"
#include "include/mlx_int.h"

int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param)
{
    t_xvar  *mlx;

    GUARD (mlx_ptr != NULL) else { RETURN("Invalid mlx pointer") }

    mlx = (t_xvar *)mlx_ptr;
    mlx->loop_hook = funct_ptr;
    mlx->loop_param = param;
    return (OK);
}