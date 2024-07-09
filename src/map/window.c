/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:27:43 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/09 15:12:03 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	my_close_tab(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	printf("test\n");
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

t_vars	init_game(t_vars vars)
{
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
	{
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "Hello world!");
	return (vars);
}

void	hook_game(t_vars vars)
{
	mlx_key_hook(vars.win, my_close, &vars);
	mlx_hook(vars.win, 17, 1L << 0, my_close_tab, &vars);
	mlx_loop(vars.mlx);
}