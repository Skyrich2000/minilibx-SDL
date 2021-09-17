# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/08/13 01:21:19 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_NAME	=	test_init_mlx
SDL_NAME	=	test_init_sdl

TEST_FILE	=	test_init.c

all			:
	gcc $(TEST_FILE) -o $(MLX_NAME) $(MLX_INCLUDE) $(MLX_CLIB)
	gcc $(TEST_FILE) -o $(SDL_NAME) $(SDL_INCLUDE) $(SDL_CLIB)

fclean			:
	rm $(MLX_NAME)
	rm $(SDL_NAME)

re				: fclean all

.PHONY: fclean all re

