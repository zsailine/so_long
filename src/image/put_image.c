/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:16:18 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/12 16:05:03 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

void	get_image(t_vars *game)
{
	int		img_width = 50;
	int		img_height = 50;

	game->luffy_f.img = mlx_xpm_file_to_image(game->mlx, "./assets/luffy-f.xpm", &img_width, &img_height);
	game->luffy_d.img = mlx_xpm_file_to_image(game->mlx, "./assets/luffy_d.xpm", &img_width, &img_height);
	game->luffy_g.img = mlx_xpm_file_to_image(game->mlx, "./assets/luffy-g.xpm", &img_width, &img_height);
	game->luffy_a.img =  mlx_xpm_file_to_image(game->mlx, "./assets/luffy_a.xpm", &img_width, &img_height);
	game->wall.img =  mlx_xpm_file_to_image(game->mlx, "./assets/mur2.xpm", &img_width, &img_height);
	game->ground.img =  mlx_xpm_file_to_image(game->mlx, "./assets/ground.xpm", &img_width, &img_height);
	game->money.img =  mlx_xpm_file_to_image(game->mlx, "./assets/money.xpm", &img_width, &img_height);
	game->portal.img = mlx_xpm_file_to_image(game->mlx, "./assets/portal.xpm", &img_width, &img_height);
	printf("(%p)\n", game->wall.img);
}

void	draw_image(int x, int y, void *img, t_vars game)
{
	mlx_put_image_to_window(game.mlx, game.win, img, x * 50, y * 50);
}

void	put_image(char **av, t_vars game)
{
	int	i;
	int	j;

	i = 0;
	get_image(&game);
	printf("[%p]\n", game.wall.img);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'P')
				draw_image(j, i, game.luffy_f.img, game);
			if (av[i][j] == '0')
			{
				printf("tafisitra\n");
				draw_image(j, i, game.ground.img, game);
			}
			if (av[i][j] == '1')
				draw_image(j, i, game.wall.img, game);
			if (av[i][j] == 'C')
				draw_image(j, i, game.money.img, game);
			if (av[i][j] == 'E')
				draw_image(j, i, game.portal.img, game);
			j++;
		}
		i++;
	}
}
