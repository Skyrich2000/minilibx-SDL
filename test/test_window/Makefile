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

MLX_NAME	=	test_window_mlx
SDL_NAME	=	test_window_sdl

TEST_FILE	=	test_window.c

all			:
	@gcc $(TEST_FILE) -o $(MLX_NAME) $(MLX_INCLUDE) $(MLX_CLIB)
	@install_name_tool -change libmlx.dylib $(MLX_PATH)/libmlx.dylib $(MLX_NAME)
#	@gcc $(TEST_FILE) -o $(SDL_NAME) $(SDL_INCLUDE) $(SDL_CLIB)

show			:
	@printf "NAME : $(NAME)\n"
	@printf "FILE : $(FILE)\n"
	@printf "OBJS : $(OBJS)\n"

fclean			:
	@rm -f $(MLX_NAME)
	@rm -f $(SDL_NAME)

re				: fclean all

.PHONY: fclean all re

