#include "mlx.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/**
 * 윈도우 창이 뜸
 * 윈도우 창을 끌 수 있음
 * 윈도우 창을 꺼도 프로그램이 종료되지 않음
 * 
 * \file mlx_new_window.c
 * \file mlx_loop.c
 */
int main()
{
    void *mlx;
    void *win;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO");

    mlx_loop(mlx);
    return (0);
}