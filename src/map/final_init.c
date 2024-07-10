/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:48:20 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/10 16:20:01 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map.h"

t_map	*final_check(char *src)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map = init_map(src, map);
	map = check_map(src, map);
	return (map);
}

