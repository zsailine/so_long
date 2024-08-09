/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strut.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:09 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 10:01:33 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUT_H

# define STRUT_H

typedef struct s_map
{
	char		**map;
}				t_map;

typedef struct s_image
{
	void		*img;
}				t_image;

typedef struct s_player
{
	int			x;
	int			y;
	int			check;
}				t_player;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_image		zorro_f;
	t_image		zorro_f1;
	t_image		zorro_f2;
	t_image		zorro_d1;
	t_image		zorro_d2;
	t_image		zorro_g1;
	t_image		zorro_g2;
	t_image		zorro_a2;
	t_image		zorro_a1;
	t_image		katana_1;
	t_image		katana_2;
	t_image		wall;
	t_image		portal;
	t_image		ground;
	t_player	player;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
}				t_vars;

#endif