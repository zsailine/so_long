/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:27:43 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/11 15:34:45 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_close_tab(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_tab(vars->map->map);
	free(vars->map);
	exit(1);
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
			"Hello world!");
	return (game);
}

void	hook_game(t_vars game)
{
	mlx_key_hook(game.win, my_close, &game);
	mlx_hook(game.win, 17, 1L << 0, my_close_tab, &game);
	mlx_loop(game.mlx);
}
