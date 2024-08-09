/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:23:05 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 13:11:37 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "so_long.h"

void	hook_game(t_vars game);
void	hook_game1(t_vars game);
int		my_close_tab(t_vars *vars);
int		my_close_tab1(t_vars *vars);
t_vars	init_game(t_vars game);
int		action(int keycode, t_vars *vars);
void	my_destroy_image(t_vars *vars);
t_vars	init_game1(t_vars game);
void	my_destroy_image1(t_vars *vars);
int		action1(int keycode, t_vars *vars);

#endif