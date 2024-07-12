# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 13:17:01 by zsailine          #+#    #+#              #
#    Updated: 2024/07/12 15:49:49 by zsailine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

MLX = lib/minilibx-linux/libmlx.a

GET = lib/get_next_line/get_next_line.c lib/get_next_line/get_utils.c lib/get_next_line/get_next_line_utils.c

SRC_M = src/map/map.c src/map/map_init.c  src/map/final_init.c

SRC_I = src/image/put_image.c src/image/window.c

SRC = main.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(GET:.c=.o)

OBJ3 = $(SRC_M:.c=.o)

OBJ4 = $(SRC_I:.c=.o)

CC = cc

MLXF = -lXext -lX11 -lm

CFLAGS = -Werror -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2) $(OBJ3) $(OBJ4)
	@make -C lib/minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(OBJ2) $(OBJ3) $(OBJ4) $(MLX) -o $(NAME) $(MLXF)

clean:
	@make clean -C lib/minilibx-linux 
	rm -f $(OBJ)
	rm -f $(OBJ2)
	rm -f $(OBJ3)
	rm -f $(OBJ4)

fclean: clean
		rm -f $(NAME)

re: fclean all
