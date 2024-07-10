/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:50:29 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/10 15:50:44 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/map.h"

int	check_impostor(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if ((map[i][j] == '1') || (map[i][j] == 'C')
			|| (map[i][j] == '0') || (map[i][j] == 'E')
			|| (map[i][j] == 'P') || (map[i][j] == '\n'))
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
} 

int	check_closed1(char *src, char **map)
{
	int	i;
	int	x;
	int	y;

	y = get_map_size(src) - 1;
	i = 0;
	x = ft_strlen(map[1]) - 2;
	while(map[y][i] != '\0')
	{
		if (map[y][i] == '1' || map[y][i] == '\n')
			i++;
		else
			return (0);
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][x] == '1' || map[i][x] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_closed(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[0][x])
	{
		if (map[0][x] == '1' || map[0][x] == '\n')
			x++;
		else
			return (0);
	}
	while (map[y] != NULL)
	{
		if (map[y][0] == '1')
			y++;
		else
			return (0);
	}
	return(1);
}

static int	check_double(int i, char **map)
{
	int	check_E;
	int	j;
	int	check_C;
	int	check_P;

	check_E = 0;
	check_C = 0;
	check_P = 0;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				check_P++;
			else if (map[i][j] == 'C')
				check_C++;
			else if (map[i][j] == 'E')
				check_E++;
		}
	}
	if (check_P != 1 || check_C < 1 || check_E != 1)
		return (0);
	return (1);
	
}

t_map	*check_map(char	*src, t_map *map)
{
	int		i;

	i = -1;
	if (map == NULL)
		return (NULL);
	if (check_impostor(map->map) == 0)
	{
		ft_printf("Error\nThere is an impostor among us!\n");
		return (free_tab(map->map), free(map), NULL);
	}
	if ((check_closed1(src, map->map) == 0) || (check_closed(map->map) == 0))
	{
		ft_printf("Error\nThis map is not closed.");
		return (free_tab(map->map), free(map), NULL);
	}
	if (check_double(i, map->map) == 0)
	{
		ft_printf("Error\nCorrect your map!");
		return (free_tab(map->map), free(map), NULL);
	}
	return (map);
}
