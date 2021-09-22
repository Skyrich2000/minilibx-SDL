# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 01:51:41 by ycha              #+#    #+#              #
#    Updated: 2021/08/19 01:51:43 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libmlx.a

FILE		=	core/mlx_init.c \
				core/mlx_loop.c \
				core/mlx_new_window.c \
				core/mlx_destroy_window.c \
				hook/mlx_loop_hook.c \
				lib/mlx_free.c

SRC_DIR		=	./src
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

# Options =================================================

CC			=	gcc
INCLUDE 	=	-I.

# =========================================================

all				: $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(INCLUDE) -c $< -o $@

$(NAME)			: $(OBJS)
	ar -rc $@ $^
	ranlib $(NAME)

show			:
	@printf "NAME : $(NAME)\n"
	@printf "FILE : $(FILE)\n"
	@printf "OBJS : $(OBJS)\n"

norm			:
	@python3 -m norminette include/*
	@python3 -m norminette src/*

test			:
	@$(MAKE) -C ./test

clean			:
	@rm -rf $(OBJ_DIR)

fclean			: clean
	@rm -f $(NAME)

re				: fclean all

.PHONY			:	all clean fclean re show test
