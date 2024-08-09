/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine < zsailine@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 08:44:26 by zsailine          #+#    #+#             */
/*   Updated: 2024/08/05 15:34:03 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/move.h"

int	move_front(t_vars *game, t_player player, int count)
{
	if ((game->map->map[player.y - 1][player.x] == '1')
		|| (game->map->map[player.y - 1][player.x] == 'E'
			&& check_portal(game) == 0))
	{
		if (game->map->map[player.y - 1][player.x] == 'E')
			ft_putendl_fd("collect all your katanas first!", 1);
		draw_player(player.x, player.y, game, 0);
		return (count);
	}
	else if ((game->map->map[player.y - 1][player.x] != '1')
		|| (game->map->map[player.y - 1][player.x] == 'E'
			&& check_portal(game) == 1))
	{
		count++;
		ft_putnbr(count);
		write(1, "\n", 1);
		if (game->map->map[player.y - 1][player.x] == 'E')
			move_portal(game, player, player.x, player.y - 1);
		game->map->map[player.y][player.x] = '0';
		game->map->map[player.y - 1][player.x] = 'P';
		draw_image(player.x, player.y, game->ground.img, game);
		draw_player(player.x, player.y - 1, game, 0);
	}
	return (count);
}

int	move_left(t_vars *game, t_player player, int count)
{
	if ((game->map->map[player.y][player.x - 1] == '1')
		|| (game->map->map[player.y][player.x - 1] == 'E'
			&& check_portal(game) == 0))
	{
		if (game->map->map[player.y][player.x - 1] == 'E')
			ft_putendl_fd("collect all your katanas first!", 1);
		draw_player(player.x, player.y, game, 1);
		return (count);
	}
	else if ((game->map->map[player.y][player.x - 1] != '1')
		|| (game->map->map[player.y][player.x - 1] == 'E'
			&& check_portal(game) == 1))
	{
		count++;
		ft_putnbr(count);
		write(1, "\n", 1);
		if (game->map->map[player.y][player.x - 1] == 'E')
			move_portal(game, player, player.x - 1, player.y);
		game->map->map[player.y][player.x] = '0';
		game->map->map[player.y][player.x - 1] = 'P';
		draw_image(player.x, player.y, game->ground.img, game);
		draw_player(player.x - 1, player.y, game, 1);
	}
	return (count);
}

int	move_back(t_vars *game, t_player player, int count)
{
	if ((game->map->map[player.y + 1][player.x] == '1')
		|| (game->map->map[player.y + 1][player.x] == 'E'
			&& check_portal(game) == 0))
	{
		if (game->map->map[player.y + 1][player.x] == 'E')
			ft_putendl_fd("collect all your katanas first!", 1);
		draw_player(player.x, player.y, game, 2);
		return (count);
	}
	else if ((game->map->map[player.y + 1][player.x] != '1')
		|| (game->map->map[player.y + 1][player.x] == 'E'
			&& check_portal(game) == 1))
	{
		count++;
		ft_putnbr(count);
		write(1, "\n", 1);
		if (game->map->map[player.y + 1][player.x] == 'E')
			move_portal(game, player, player.x, player.y + 1);
		game->map->map[player.y][player.x] = '0';
		game->map->map[player.y + 1][player.x] = 'P';
		draw_image(player.x, player.y, game->ground.img, game);
		draw_player(player.x, player.y + 1, game, 2);
	}
	return (count);
}

int	move_right(t_vars *game, t_player player, int count)
{
	if ((game->map->map[player.y][player.x + 1] == '1')
		|| (game->map->map[player.y][player.x + 1] == 'E'
			&& check_portal(game) == 0))
	{
		if (game->map->map[player.y][player.x + 1] == 'E')
			ft_putendl_fd("collect all your katanas first!", 1);
		draw_player(player.x, player.y, game, 3);
		return (count);
	}
	else if ((game->map->map[player.y][player.x + 1] != '1')
		|| (game->map->map[player.y][player.x + 1] == 'E'
			&& check_portal(game) == 1))
	{
		count++;
		ft_putnbr(count);
		write(1, "\n", 1);
		if (game->map->map[player.y][player.x + 1] == 'E')
			move_portal(game, player, player.x + 1, player.y);
		game->map->map[player.y][player.x] = '0';
		game->map->map[player.y][player.x + 1] = 'P';
		draw_image(player.x, player.y, game->ground.img, game);
		draw_player(player.x + 1, player.y, game, 3);
	}
	return (count);
}

void	move_player(int keycode, t_vars *game)
{
	t_player	player;
	static int	count;

	player = get_player(game->map->map);
	if (keycode == 'w')
		count = move_front(game, player, count);
	else if (keycode == 'a')
		count = move_left(game, player, count);
	else if (keycode == 's')
		count = move_back(game, player, count);
	else if (keycode == 'd')
		count = move_right(game, player, count);
}
