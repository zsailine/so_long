/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:16:18 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 11:34:42 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/image.h"

void	image1(t_vars *game)
{
	int	img_width;
	int	img_height;

	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/mur.xpm",
			&img_width, &img_height);
	game->ground.img = mlx_xpm_file_to_image(game->mlx, "./assets/ground.xpm",
			&img_width, &img_height);
	game->katana_1.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/katana1.xpm", &img_width, &img_height);
	game->katana_2.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/katana2.xpm", &img_width, &img_height);
	game->portal.img = mlx_xpm_file_to_image(game->mlx, "./assets/portal.xpm",
			&img_width, &img_height);
}

void	get_image(t_vars *game)
{
	int	img_width;
	int	img_height;

	game->zorro_g1.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/zorro_g1.xpm", &img_width, &img_height);
	game->zorro_g2.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/zorro_g2.xpm", &img_width, &img_height);
	game->zorro_f.img = mlx_xpm_file_to_image(game->mlx, "./assets/zorro_f.xpm",
			&img_width, &img_height);
	game->zorro_f2.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/zorro_f2.xpm", &img_width, &img_height);
	game->zorro_f1.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/zorro_f1.xpm", &img_width, &img_height);
	game->zorro_d1.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/zorro_d1.xpm", &img_width, &img_height);
	game->zorro_d2.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/zorro_d2.xpm", &img_width, &img_height);
	game->zorro_a1.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/zorro_a1.xpm", &img_width, &img_height);
	game->zorro_a2.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/zorro_a2.xpm", &img_width, &img_height);
	image1(game);
}

void	draw_image(int x, int y, void *img, t_vars *game)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 50, y * 50);
}

void	draw_katana(int j, int i, t_vars *game)
{
	static int	tmp;

	if (tmp % 2 == 0)
		draw_image(j, i, game->katana_1.img, game);
	else
		draw_image(j, i, game->katana_2.img, game);
	tmp++;
}

void	put_image(t_vars *game)
{
	int	i;
	int	j;

	i = 0;
	game->player.check = 1;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'P')
				draw_image(j, i, game->zorro_f.img, game);
			if (game->map->map[i][j] == '0')
				draw_image(j, i, game->ground.img, game);
			if (game->map->map[i][j] == '1')
				draw_image(j, i, game->wall.img, game);
			if (game->map->map[i][j] == 'C')
				draw_katana(j, i, game);
			if (game->map->map[i][j] == 'E')
				draw_image(j, i, game->portal.img, game);
			j++;
		}
		i++;
	}
}
