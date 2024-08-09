/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:23:50 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 13:26:20 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/move.h"

int	check_portal1(t_vars *game)
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

void	move_portal1(t_vars *game, t_player player, int x, int y)
{
	game->map->map[player.y][player.x] = '0';
	game->map->map[y][x] = 'P';
	draw_image1(player.x, player.y, game->ground.img, game);
	draw_image1(x, y, game->zorro_f1.img, game);
	ft_putendl_fd("Don't get lost next time!", 1);
	my_close_tab1(game);
}
