/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:48:20 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/17 10:52:33 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

t_map	*check(char *src, t_map *map)
{
	map = init_map(src, map);
	if (map == NULL)
		return (NULL);
	map = check_map(src, map);
	if (map == NULL)
		return (NULL);
	return (map);
}

t_map	*final_check(char *src)
{
	t_map		*map;
	t_player	player;
	char		**tmp;
	int			i;

	map = malloc(sizeof(t_map));
	map = check(src, map);
	if (map == NULL)
		return (NULL);
	i = get_map_size(src);
	tmp = insert_map(src, i);
	player = get_player(tmp);
	floodfill(tmp, player.x, player.y);
	while (--i)
	{
		if (ft_strchr(tmp[i], 'C') || ft_strchr(tmp[i], 'P'))
		{
			ft_putendl_fd("Error\nNah you wouldn't win", 2);
			return (free_tab(map->map), free(map), free_tab(tmp), NULL);
		}
	}
	return (free_tab(tmp), map);
}

t_player	get_player(char **src)
{
	t_player	player;
	int			i;
	int			j;

	i = -1;
	while (src[++i] != NULL)
	{
		j = -1;
		while (src[i][++j])
		{
			if (src[i][j] == 'P')
			{
				player.y = i;
				player.x = j;
			}
		}
	}
	return (player);
}

void	floodfill(char **src, int x, int y)
{
	if (src[y][x] == '1' || src[y][x] == 'F'|| src[y][x] == 'E')
		return ;
	src[y][x] = 'F';
	floodfill(src, x + 1, y);
	floodfill(src, x - 1, y);
	floodfill(src, x, y + 1);
	floodfill(src, x, y - 1);
}
