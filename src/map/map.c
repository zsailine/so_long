/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:22:57 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/09 16:30:01 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

int	get_map_size(char *src)
{
	int		fd;
	int		i;
	char	*dest;

	i = 0;
	fd = open(src, O_RDONLY);
	while (1)
	{
		dest = get_next_line(fd);
		if (dest == NULL)
			break ;
		free(dest);
		i++;
	}
	close (fd);
	return (i);
}

int	get_map_rect(char *src)
{
	int 	fd;
	size_t	tmp;
	size_t	size;
	char 	*dest;

	fd = open(src, O_RDONLY);
	dest = get_next_line(fd);
	size = ft_strlen((char *)dest);
	free(dest);
	while (dest)
	{
		dest = get_next_line(fd);
		if (dest == NULL)
			break ;
		tmp = ft_strlen((char *)dest);
		if (ft_strchr((char *)dest, '\n') == 0)
			tmp++;
		if (tmp != size)
			break ;
		free(dest);
	}
	close (fd);
	if (tmp != size)
		return (0);
	return (tmp);
}

static int	ft_check_file(char *src)
{
	int		i;
	int		j;
	int		z;
	char	*cmp;

	i = ft_strlen((char *)src) + 1;
	j = 0;
	z = 0;
	while (--i)
	{
		j++;
		if (src[i] == '.')
		{
			cmp = malloc(sizeof(char) * j);
			while (j--)
				cmp[z++] = src[i++];
			if (ft_strcmp((char *)cmp, ".ber") == 0)
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

// static char	**insert_map(char *src, int	size)
// {
// 	int		fd;
// 	int		i;
// 	char	**dest;

// 	dest = malloc(sizeof(char *) * (size + 1));
// 	i = 0;
// 	fd = open(src, O_RDONLY);
// 	while (1)
// 	{
// 		dest[i++] = get_next_line(fd);
// 		if (dest[i] == NULL)
// 			break ;
// 	}
// 	printf("%s\n", dest[i]);
// 	dest[i] = '\0';
// 	close (fd);
// 	return (dest);
// }

int	init_map(char *src)
{
	//t_map	*size;
	//int		i;

	//size = malloc(sizeof(t_map));
	if (get_map_size(src) == 0)
	{
		ft_printf("Error\nThis map doesn't exist!\n");
		return (0);
	}
	else if (ft_check_file(src) == 0)
	{
		ft_printf("Error\nFile not supported!\n");
		return (0);
	}
	else if (get_map_rect(src) == 0)
	{
		ft_printf("Error\nThis map is not rectangular!\n");
		return (0);
	}
	//i = get_map_size(src);
	//size->map = insert_map(src, i);
	return (1);
}