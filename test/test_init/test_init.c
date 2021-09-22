#include "mlx.h"
#include <stdio.h>
/**
 * 초기화가 됨
 * 
 * \file mlx_init.c
 */
int main()
{
    void *mlx;
    
    mlx = mlx_init();
    printf("return : %p", mlx);
    return (0);
}