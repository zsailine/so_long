/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:02:37 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/10 15:51:00 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

# include "so_long.h"

int		get_map_size(char *src);
int		get_map_rect(char *src);
t_map	*init_map(char *src, t_map *size);
t_map	*check_map(char	*src, t_map *map);
int		check_impostor(char **map);
int		check_closed1(char *src, char **map);
int		check_closed(char **map);
t_map	*final_check(char *src);

#endif