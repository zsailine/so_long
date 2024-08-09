# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 13:17:01 by zsailine          #+#    #+#              #
#    Updated: 2024/07/16 13:45:03 by zsailine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

NAME_BONUS = so_long_bonus

MLX = lib/minilibx-linux/libmlx.a

GET = lib/get_next_line/get_next_line.c lib/get_next_line/get_utils.c lib/get_next_line/get_next_line_utils.c

SRC_M = src/map/map.c src/map/map_init.c  src/map/final_init.c

SRC_I = src/image/put_image_bonus.c src/image/window_bonus.c

SRC_P = src/move/move_bonus.c src/move/update_bonus.c

SRC_P1 = src/move/move.c src/move/update.c

SRC_I1 = src/image/put_image.c src/image/window.c

SRC = main_bonus.c

SRC1 = main.c

OBJ_2 = $(SRC1:.c=.o)

OBJ_B1 = $(SRC_I1:.c=.o)

OBJ_B2 = $(SRC_P1:.c=.o)

OBJ = $(SRC:.c=.o)

OBJ2 = $(GET:.c=.o)

OBJ3 = $(SRC_M:.c=.o)

OBJ4 = $(SRC_I:.c=.o)

OBJ5 =  $(SRC_P:.c=.o)

CC = cc

MLXF = -lXext -lX11 -lm

CFLAGS = -Werror -Wall -Wextra -g -s

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)
	@make -C lib/minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(MLX) -o $(NAME_BONUS) $(MLXF)

$(NAME): $(OBJ_2) $(OBJ_B1) $(OBJ_B2) $(OBJ2) $(OBJ3)
			@make -C lib/minilibx-linux
			$(CC) $(CFLAGS) $(SRC1) $(SRC_1) $(SRC_I1) $(SRC_P1) $(GET) $(SRC_M) $(MLX) -o $(NAME) $(MLXF)
clean:
	@make clean -C lib/minilibx-linux 
	rm -f $(OBJ)
	rm -f $(OBJ2)
	rm -f $(OBJ3)
	rm -f $(OBJ4)
	rm -f $(OBJ5)
	rm -f $(OBJ_2)
	rm -f $(OBJ_B1)
	rm -f $(OBJ_B2)

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_BONUS)

re: fclean all clean
