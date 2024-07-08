/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:42:21 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/08 10:38:46 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	main(void)
// {
// 	t_vars	vars;
// 	t_data	img;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, MAX_WIDTH, MAX_LENGTH, "Hello world!");
// 	img.img = mlx_new_image(vars.mlx, MAX_WIDTH, MAX_LENGTH);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// draw_line(&img);
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 	mlx_loop(vars.mlx);
// }

int	my_close_tab(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
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

int	main(void)
{
	t_vars	vars;
	char	*relative_path = "assets/luffy_a.xpm";
	int		img_width = 0;
	int		img_height = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, MAX_WIDTH, MAX_LENGTH, "Hello world!");
	vars.img =  mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 50, 50);
	mlx_key_hook(vars.win, my_close, &vars);
	mlx_hook(vars.win, 17, 1L << 0, my_close_tab, &vars);
	mlx_loop(vars.mlx);
}
