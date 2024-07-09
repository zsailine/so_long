/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:02:37 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/09 16:27:29 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

# include "so_long.h"

int		get_map_size(char *src);
int		get_map_rect(char *src);
int		init_map(char *src);

#endif