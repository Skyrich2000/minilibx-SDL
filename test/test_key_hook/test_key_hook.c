#include "mlx.h"
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/**
 * 키보드 누를떄, 땔때 마다 출력이 되어야함
 * keycode 가 제대로된 값이 나와야함
 * 
 * \file mlx_loop.c
 * \file mlx_key_hook.c
 */

int key_hooked_press(int keycode, void *param)
{
    printf("key press code %d, param %d\n", keycode, *(int *)param);
    return (0);
}

int key_hooked_release(int keycode, void *param)
{
    printf("key release code %d, param %d\n", keycode, *(int *)param);
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
    // mlx_key_hook(win, key_hooked, &num);
    mlx_hook(win, 2, 0, key_hooked_press, &num);
    mlx_hook(win, 3, 0, key_hooked_release, &num);
    
    mlx_loop(mlx);
    return (0);
}