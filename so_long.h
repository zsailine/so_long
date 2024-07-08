/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:44:32 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/08 16:12:11 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# ifndef MAX_LENGTH
#  define MAX_LENGTH 580
# endif

# ifndef MAX_WIDTH
#  define MAX_WIDTH 720
# endif

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;


#endif 
