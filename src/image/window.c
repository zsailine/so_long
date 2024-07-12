/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:27:43 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/12 16:07:03 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window.h"

void	my_destroy_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->luffy_f.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->luffy_g.img);
	mlx_destroy_image(vars->mlx, vars->luffy_a.img);
	mlx_destroy_image(vars->mlx, vars->luffy_d.img);
	mlx_destroy_image(vars->mlx, vars->money.img);
	mlx_destroy_image(vars->mlx, vars->ground.img);
	mlx_destroy_image(vars->mlx, vars->portal.img);
}

int	my_close_tab(t_vars *vars)
{
	my_destroy_image(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_tab(vars->map->map);
	free(vars->map);
	exit(EXIT_SUCCESS);
}

int	my_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		my_close_tab(vars);
	}
	return (0);
}

t_vars	init_game(t_vars game)
{
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	game.win = mlx_new_window(game.mlx, game.width, game.height,
			"So long");
	return (game);
}

void	hook_game(t_vars game)
{
	mlx_key_hook(game.win, my_close, &game);
	mlx_hook(game.win, 17, 1L << 0, my_close_tab, &game);
	mlx_loop(game.mlx);
}
