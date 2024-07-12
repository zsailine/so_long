/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strut.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:09 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/12 09:42:38 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUT_H

# define STRUT_H

typedef struct s_map
{
	char	**map;
}		t_map;

typedef struct s_image
{
	void	*img;
}				t_image;

typedef struct s_player
{
	int	x;
	int	y;
	int	check;
}		t_player;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_image	luffy_f;
	t_image	luffy_d;
	t_image	luffy_g;
	t_image	luffy_a;
	t_image	wall;
	t_image	money;
	t_image	portal;
	t_image	ground;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
}				t_vars;

#endif