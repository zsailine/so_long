# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 13:17:01 by zsailine          #+#    #+#              #
#    Updated: 2024/07/04 14:07:48 by zsailine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

MLX = minilibx-linux/libmlx.a

GET = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRC = main.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(GET:.c=.o)

CC = cc

MLXF = -lXext -lX11 -lm

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(OBJ2) $(MLX) -o $(NAME) $(MLXF)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME)

re: fclean all
