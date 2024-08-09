/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine < zsailine@student.42antananar    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 08:44:26 by zsailine          #+#    #+#             */
/*   Updated: 2024/08/05 15:27:50 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/move.h"

int	move_front1(t_vars *game, t_player player, int count)
{
	if ((game->map->map[player.y - 1][player.x] == '1')
		|| (game->map->map[player.y - 1][player.x] == 'E'
			&& check_portal1(game) == 0))
	{
		if (game->map->map[player.y - 1][player.x] == 'E')
			ft_putendl_fd("collect all your katanas first!", 1);
		draw_image1(player.x, player.y, game->zorro_a1.img, game);
		return (count);
	}
	else if ((game->map->map[player.y - 1][player.x] != '1')
		|| (game->map->map[player.y - 1][player.x] == 'E'
			&& check_portal1(game) == 1))
	{
		count++;
		ft_putnbr(count);
		write(1, "\n", 1);
		if (game->map->map[player.y - 1][player.x] == 'E')
			move_portal1(game, player, player.x, player.y - 1);
		game->map->map[player.y][player.x] = '0';
		game->map->map[player.y - 1][player.x] = 'P';
		draw_image1(player.x, player.y, game->ground.img, game);
		draw_image1(player.x, player.y - 1, game->zorro_a1.img, game);
	}
	return (count);
}

int	move_left1(t_vars *game, t_player player, int count)
{
	if ((game->map->map[player.y][player.x - 1] == '1')
		|| (game->map->map[player.y][player.x - 1] == 'E'
			&& check_portal1(game) == 0))
	{
		if (game->map->map[player.y][player.x - 1] == 'E')
			ft_putendl_fd("collect all your katanas first!", 1);
		draw_image1(player.x, player.y, game->zorro_g1.img, game);
		return (count);
	}
	else if ((game->map->map[player.y][player.x - 1] != '1')
		|| (game->map->map[player.y][player.x - 1] == 'E'
			&& check_portal1(game) == 1))
	{
		count++;
		ft_putnbr(count);
		write(1, "\n", 1);
		if (game->map->map[player.y][player.x - 1] == 'E')
			move_portal1(game, player, player.x - 1, player.y);
		game->map->map[player.y][player.x] = '0';
		game->map->map[player.y][player.x - 1] = 'P';
		draw_image1(player.x, player.y, game->ground.img, game);
		draw_image1(player.x - 1, player.y, game->zorro_g1.img, game);
	}
	return (count);
}

int	move_back1(t_vars *game, t_player player, int count)
{
	if ((game->map->map[player.y + 1][player.x] == '1')
		|| (game->map->map[player.y + 1][player.x] == 'E'
			&& check_portal1(game) == 0))
	{
		if (game->map->map[player.y + 1][player.x] == 'E')
			ft_putendl_fd("collect all your katanas first!", 1);
		draw_image1(player.x, player.y, game->zorro_f1.img, game);
		return (count);
	}
	else if ((game->map->map[player.y + 1][player.x] != '1')
		|| (game->map->map[player.y + 1][player.x] == 'E'
			&& check_portal1(game) == 1))
	{
		count++;
		ft_putnbr(count);
		write(1, "\n", 1);
		if (game->map->map[player.y + 1][player.x] == 'E')
			move_portal1(game, player, player.x, player.y + 1);
		game->map->map[player.y][player.x] = '0';
		game->map->map[player.y + 1][player.x] = 'P';
		draw_image1(player.x, player.y, game->ground.img, game);
		draw_image1(player.x, player.y + 1, game->zorro_f1.img, game);
	}
	return (count);
}

int	move_right1(t_vars *game, t_player player, int count)
{
	if ((game->map->map[player.y][player.x + 1] == '1')
		|| (game->map->map[player.y][player.x + 1] == 'E'
			&& check_portal1(game) == 0))
	{
		if (game->map->map[player.y][player.x + 1] == 'E')
			ft_putendl_fd("collect all your katanas first!", 1);
		draw_image1(player.x, player.y, game->zorro_d1.img, game);
		return (count);
	}
	else if ((game->map->map[player.y][player.x + 1] != '1')
		|| (game->map->map[player.y][player.x + 1] == 'E'
			&& check_portal1(game) == 1))
	{
		count++;
		ft_putnbr(count);
		write(1, "\n", 1);
		if (game->map->map[player.y][player.x + 1] == 'E')
			move_portal1(game, player, player.x + 1, player.y);
		game->map->map[player.y][player.x] = '0';
		game->map->map[player.y][player.x + 1] = 'P';
		draw_image1(player.x, player.y, game->ground.img, game);
		draw_image1(player.x + 1, player.y, game->zorro_d1.img, game);
	}
	return (count);
}

void	move_player1(int keycode, t_vars *game)
{
	t_player	player;
	static int	count;

	player = get_player(game->map->map);
	if (keycode == 'w')
		count = move_front1(game, player, count);
	else if (keycode == 'a')
		count = move_left1(game, player, count);
	else if (keycode == 's')
		count = move_back1(game, player, count);
	else if (keycode == 'd')
		count = move_right1(game, player, count);
}
