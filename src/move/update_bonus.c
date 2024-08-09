/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:01:26 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 12:27:01 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/move.h"

void	draw_player1(int j, int i, t_vars *game, int check)
{
	if (check == 2)
		draw_image(j, i, game->zorro_f1.img, game);
	if (check == 1)
		draw_image(j, i, game->zorro_g1.img, game);
	if (check == 0)
		draw_image(j, i, game->zorro_a1.img, game);
	if (check == 3)
		draw_image(j, i, game->zorro_d1.img, game);
}

void	draw_player(int j, int i, t_vars *game, int check)
{
	if (game->player.check == 1)
	{
		draw_player1(j, i, game, check);
		game->player.check = 0;
		return ;
	}
	else
	{
		if (check == 2)
			draw_image(j, i, game->zorro_f2.img, game);
		if (check == 1)
			draw_image(j, i, game->zorro_g2.img, game);
		if (check == 0)
			draw_image(j, i, game->zorro_a2.img, game);
		if (check == 3)
			draw_image(j, i, game->zorro_d2.img, game);
		game->player.check = 1;
		return ;
	}
}

int	check_portal(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	move_portal(t_vars *game, t_player player, int x, int y)
{
	game->map->map[player.y][player.x] = '0';
	game->map->map[y][x] = 'P';
	draw_image(player.x, player.y, game->ground.img, game);
	draw_image(x, y, game->zorro_f.img, game);
	ft_putendl_fd("Don't get lost next time!", 1);
	my_close_tab(game);
}
