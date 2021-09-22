#include "mlx.h"
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/**
 * loop hooked with param 10! 가 계속 나온다.
 * 두번 정의 하면 마지막에 정의한거만 호출됨
 * 
 * \file mlx_loop.c
 * \file mlx_loop_hook.c
 */

int loop_hooked()
{
    printf("loop hooked!\n");
    return (0);
}

int loop_hooked_with_param(void *param)
{
    int num;

    num = *(int *)param;
    printf("loop hooked with param %d!\n", num);
    return (0);
}

int main()
{
    void *mlx;
    void *win;
    int num;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO");

    num = 10;
    mlx_loop_hook(mlx, loop_hooked, 0);
    mlx_loop_hook(mlx, loop_hooked_with_param, &num);
    
    mlx_loop(mlx);
    return (0);
}