# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 13:17:01 by zsailine          #+#    #+#              #
#    Updated: 2024/07/09 13:13:56 by zsailine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

MLX = lib/minilibx-linux/libmlx.a

FT_PRINTF = lib/ft_printf/libftprintf.a

GET = lib/get_next_line/get_next_line.c lib/get_next_line/get_utils.c lib/get_next_line/get_next_line_utils.c

SRC_M = src/map/window.c src/map/map.c

SRC = main.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(GET:.c=.o)

OBJ3 = $(SRC_M:.c=.o)

CC = cc

MLXF = -lXext -lX11 -lm

CFLAGS = -Werror -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2) $(OBJ3)
	@make -C lib/minilibx-linux
	@make -C lib/ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(OBJ2) $(OBJ3) $(MLX) $(FT_PRINTF) -o $(NAME) $(MLXF)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)
	rm -f $(OBJ3)

fclean: clean
	rm -f $(NAME)

re: fclean all
