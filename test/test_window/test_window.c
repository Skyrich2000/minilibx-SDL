#include "mlx.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main()
{
    void *mlx;
    void *win;

    void *mlx2;
    void *win2;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO");

    mlx2 = mlx_init();
    win2 = mlx_new_window(mlx2, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO2");

    mlx_loop(mlx);
    return (0);
}