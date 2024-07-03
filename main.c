/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:42:21 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/03 13:16:21 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	draw_line(t_data *data)
{
	int	x = 0;
	int	y = MAX_WIDTH - 1;
	while (x <= MAX_LENGTH - 1)
	{
		my_mlx_pixel_put(data, x, (MAX_WIDTH - 1), 0x00FF0000);
		x++;
	}
	x = 0;
	while (x <= MAX_LENGTH/2)
	{
		my_mlx_pixel_put(data, x, y, 0x00FF0000);
		x++;
		y--;
	}
	while (y <= (MAX_WIDTH - 1))
	{
		my_mlx_pixel_put(data, x, y, 0x00FF0000);
		y++;
		x++;
	}
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, MAX_LENGTH, MAX_WIDTH, "Hello world!");
// 	img.img = mlx_new_image(mlx, MAX_LENGTH, MAX_WIDTH);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	draw_line(&img);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}

