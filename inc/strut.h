/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strut.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:49:09 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/09 15:34:40 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct	s_vars
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
}				t_vars;

typedef struct	s_map
{
	char	**map;
	int		x;
	int		y;
}		t_map;

#endif