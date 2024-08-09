/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 08:44:52 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 12:52:29 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H

# define MOVE_H

# include "so_long.h"

void	move_portal(t_vars *game, t_player player, int x, int y);
void	move_player(int keycode, t_vars *game);
int		move_front(t_vars *game, t_player player, int count);
int		move_back(t_vars *game, t_player player, int count);
int		move_left(t_vars *game, t_player player, int count);
int		move_right(t_vars *game, t_player player, int count);
int		check_portal(t_vars *game);
void	draw_player(int j, int i, t_vars *game, int check);
void	move_player1(int keycode, t_vars *game);
int		check_portal1(t_vars *game);
void	move_portal1(t_vars *game, t_player player, int x, int y);
int		move_front1(t_vars *game, t_player player, int count);
int		move_back1(t_vars *game, t_player player, int count);
int		move_left1(t_vars *game, t_player player, int count);
int		move_right1(t_vars *game, t_player player, int count);

#endif