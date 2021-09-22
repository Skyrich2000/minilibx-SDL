#include "mlx.h"

/**
 * 무한루프가 돌아감
 * ^C 로 프로그램 강제 종료 가능 exit(130)
 * ^\ 로 프로그램 강제 종료 가능
 * 
 * \file mlx_loop.c
 * \file mlx_init.c
 */
int main()
{
    void *mlx;

    mlx = mlx_init();

    mlx_loop(mlx);
    return (0);
}