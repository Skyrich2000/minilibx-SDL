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

FILE		=	mlx_init.c

SRC_DIR		=	./src
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

# Options =================================================

CC			=	gcc
INCLUDE 	=	-Iinclude -I.
CLIB		=	-lSDL2 -lSDL2_image

# =========================================================

all				: $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(INCLUDE) $(CLIB) -c $< -o $@

$(NAME)			: $(OBJS)
	ar -r $(NAME) $(OBJ)
	ranlib $(NAME)

show			:
	@printf "NAME : $(NAME)\n"
	@printf "FILE : $(FILE)\n"
	@printf "OBJS : $(OBJS)\n"

norm			:
	@python3 -m norminette include/*
	@python3 -m norminette src/*

test			:
	$(MAKE)	-C ./test

clean			:
	@rm -rf $(OBJ_DIR)

fclean			: clean
	@rm -f $(NAME)

re				: fclean all

.PHONY			:	all clean fclean re bonus show norm run
