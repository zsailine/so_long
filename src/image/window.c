/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:25:52 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 14:01:04 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window.h"

void	my_destroy_image1(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->katana_1.img);
	mlx_destroy_image(vars->mlx, vars->katana_2.img);
	mlx_destroy_image(vars->mlx, vars->ground.img);
	mlx_destroy_image(vars->mlx, vars->portal.img);
	mlx_destroy_image(vars->mlx, vars->zorro_f1.img);
	mlx_destroy_image(vars->mlx, vars->zorro_a1.img);
	mlx_destroy_image(vars->mlx, vars->zorro_d1.img);
	mlx_destroy_image(vars->mlx, vars->zorro_g1.img);
}

t_vars	init_game1(t_vars game)
{
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		write(2, "Error\n", 6);
		free(game.mlx);
		exit(EXIT_FAILURE);
	}
	game.win = mlx_new_window(game.mlx, game.width, game.height, "So long");
	return (game);
}

int	my_close_tab1(t_vars *vars)
{
	my_destroy_image1(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_tab(vars->map->map);
	free(vars->map);
	exit(EXIT_SUCCESS);
}

int	action1(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		ft_putendl_fd("escape pressed", 1);
		my_close_tab1(vars);
	}
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		move_player1(keycode, vars);
	return (0);
}

void	hook_game1(t_vars game)
{
	mlx_key_hook(game.win, action1, &game);
	mlx_hook(game.win, 17, 1L << 0, my_close_tab1, &game);
	mlx_loop(game.mlx);
}
