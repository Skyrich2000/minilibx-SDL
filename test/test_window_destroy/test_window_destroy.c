#include "mlx.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO");
    mlx_destroy_window(mlx, win);

    mlx_loop(mlx);
    return (0);
}