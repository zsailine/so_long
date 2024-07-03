# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 13:17:01 by zsailine          #+#    #+#              #
#    Updated: 2024/07/03 10:40:50 by zsailine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

MLX = minilibx-linux/libmlx.a

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = cc

MLXF = -lXext -lX11 -lm

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) -I include $(MLX) -I/usr/include/SDL2 -D_REENTRANT -lSDL2 -o $(NAME) $(MLXF)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all