/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strut.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:09 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/11 16:11:03 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUT_H

# define STRUT_H

typedef struct s_map
{
	char	**map;
}		t_map;

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
}				t_vars;

#endif