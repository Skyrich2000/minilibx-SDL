#include "mlx.h"

/**
 * 이미지가 정상적으로 로딩이 된다
 * 
 * \file mlx_png_file_to_image.c
 * \file mlx_init.c
 */
int main()
{
    void *mlx;

    mlx = mlx_init();

    mlx_loop(mlx);
    return (0);
}