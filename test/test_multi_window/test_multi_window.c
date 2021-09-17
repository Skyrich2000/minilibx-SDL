#include "mlx.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main()
{
    void *mlx1;
    void *win1_1;
    void *win1_2;
    
    void *mlx2;
    void *win2_1;

    mlx1 = mlx_init();
    win1_1 = mlx_new_window(mlx1, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO window 1_1");
    win1_2 = mlx_new_window(mlx1, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO window 1_2");

    mlx2 = mlx_init();
    win2_1 = mlx_new_window(mlx2, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO window 2_1");

    mlx_loop(mlx1);
    mlx_loop(mlx2);
    return (0);
}