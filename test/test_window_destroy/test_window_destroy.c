#include "mlx.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void *mlx;
void *win;

int key_hook(int keycode)
{
    if (keycode == 0)
        mlx_destroy_window(mlx, win);
    return (0);
}

int main()
{
    mlx = mlx_init();
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO");

    mlx_hook(win, 2, 0, key_hook, 0);
    mlx_loop(mlx);
    return (0);
}