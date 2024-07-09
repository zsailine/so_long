/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:23:05 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/09 09:48:47 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "so_long.h"

void	hook_game(t_vars vars);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int		my_close_tab(t_vars *vars);
t_vars	init_game(t_vars vars);

#endif