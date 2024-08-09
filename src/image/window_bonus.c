/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:27:43 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 11:26:29 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window.h"

void	my_destroy_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->zorro_f.img);
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->zorro_f1.img);
	mlx_destroy_image(vars->mlx, vars->zorro_f2.img);
	mlx_destroy_image(vars->mlx, vars->zorro_a1.img);
	mlx_destroy_image(vars->mlx, vars->zorro_a2.img);
	mlx_destroy_image(vars->mlx, vars->zorro_d1.img);
	mlx_destroy_image(vars->mlx, vars->zorro_d2.img);
	mlx_destroy_image(vars->mlx, vars->zorro_g1.img);
	mlx_destroy_image(vars->mlx, vars->zorro_g2.img);
	mlx_destroy_image(vars->mlx, vars->katana_1.img);
	mlx_destroy_image(vars->mlx, vars->katana_2.img);
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

int	action(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		ft_putendl_fd("escape pressed", 1);
		my_close_tab(vars);
	}
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		move_player(keycode, vars);
	return (0);
}

t_vars	init_game(t_vars game)
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

void	hook_game(t_vars game)
{
	mlx_key_hook(game.win, action, &game);
	mlx_hook(game.win, 17, 1L << 0, my_close_tab, &game);
	mlx_loop(game.mlx);
}
