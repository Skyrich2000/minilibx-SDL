#include "mlx.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/**
 * 빈 화면일떄, fps 확인
 * mlx : 10000 근처
 * sdl(surface) : 80 근처
 * 
 * \file mlx_loop.c
 * \file mlx_loop_hook.c
 */

struct timeval  tv;
double begin, end;

int loop_hooked()
{
    static int count = 0;
    clock_t end;

    count++;
    gettimeofday(&tv, NULL);
	end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
    // printf("%f\n", (float)(end - start)/CLOCKS_PER_SEC);
    if ((end - begin) / 1000 > 1.0)
    {
        printf("fps : %d\n", count);
        begin = end;
        count = 0;
    }
    return (0);
}

int main()
{
    void *mlx;
    void *win;
    void *win2;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO");
    win2 = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "HELLO");

    mlx_loop_hook(mlx, loop_hooked, 0);
    
    gettimeofday(&tv, NULL);
	begin = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
    mlx_loop(mlx);
    return (0);
}