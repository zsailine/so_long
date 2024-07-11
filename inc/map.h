/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:02:37 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/11 16:16:59 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

# include "so_long.h"

int			get_map_size(char *src);
int			get_map_rect(char *src);
t_map		*init_map(char *src, t_map *size);
t_map		*check_map(char	*src, t_map *map);
int			check_impostor(char **map);
int			check_closed1(char *src, char **map);
int			check_closed(char **map);
t_map		*final_check(char *src);
char		**insert_map(char *src, int size);
t_player	get_player(char **src);
void		floodfill(char **src, int x, int y);
void		image_to_put(int y, int x, int check, t_vars game);
void		put_image(char **av, t_vars game);
void		draw_map(char *relative_path, int y, int x, t_vars tmp);

#endif