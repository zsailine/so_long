/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:16:18 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/11 16:11:39 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

void	put_image(char **av, t_vars game)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i][j])
	{
		j = -1;
		while (av[i][--j])
		{
			if ((av[i][j] = 'P'))
				image_to_put(i, j, 0, game);
			else if ((av[i][j] = '0'))
				image_to_put(i, j, 1, game);
			else if ((av[i][j] = 'W'))
				image_to_put(i, j, 2, game);
			else if ((av[i][j] = '1'))
				image_to_put(i, j, 3, game);
			else if ((av[i][j] = 'E'))
				image_to_put(i, j, 4, game);
		}
	}
}

void	image_to_put(int y, int x, int check, t_vars game)
{
	char	*luffy_f;
	char	*ground;
	char	*wall;
	char	*money;
	char	*portal;

	luffy_f = "../../assets/luffy-f.xpm";
	ground = "../../assets/ground.xpm";
	wall = "../../assets/wall.xpm";
	money = "../../assets/money.xpm";
	portal = "../../assets/portal.xpm";
	if (check == 0)
		draw_map(luffy_f, y, x, game);
	if (check == 1)
		draw_map(ground, y, x, game);
	if (check == 2)
		draw_map(wall, y, x, game);
	if (check == 3)
		draw_map(money, y, x, game);
	if (check == 4)
		draw_map(portal, y, x, game);
}

void	draw_map(char *relative_path, int y, int x, t_vars tmp)
{
	t_vars	game;
	int		img_width;
	int		img_height;

	game.img =  mlx_xpm_file_to_image(tmp.mlx, relative_path, &img_width, &img_height);
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);
	mlx_put_image_to_window(tmp.mlx, tmp.win, game.img, x * 50, y * 50);
	hook_game(game);
}