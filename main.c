/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:42:21 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/06 09:07:51 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	my_close_tab(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
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

void	draw_line(t_data *data)
{
	int	x = 0;
	int	y = MAX_LENGTH - 1;
	while (x <= MAX_WIDTH - 1)
	{
		my_mlx_pixel_put(data, x, (MAX_LENGTH - 1), 0x00FF0000);
		x++;
	}
	x = 0;
	while (x <= MAX_WIDTH/2)
	{
		my_mlx_pixel_put(data, x, y, 0x00FF0000);
		x++;
		y--;
	}
	while (y <= (MAX_LENGTH - 1))
	{
		my_mlx_pixel_put(data, x, y, 0x00FF0000);
		y++;
		x++;
	}
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

int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_data	img1;
	char	*relative_path = "./test.xpm";
	int		img_width = MAX_WIDTH;
	int		img_height = MAX_LENGTH;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, MAX_WIDTH, MAX_LENGTH, "Hello world!");
	img1.img = mlx_new_image(vars.mlx, MAX_WIDTH, MAX_LENGTH);
	img1.addr =	mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.line_length, &img1.endian);	
	img.img =  mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img1.img, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 50, 50);
	vars.img.img = img.img;
	mlx_key_hook(vars.win, my_close, &vars);
	draw_line(&img1);
	mlx_hook(vars.win, 17, 1L << 0, my_close_tab, &vars);
	mlx_loop(vars.mlx);
}
