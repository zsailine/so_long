/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:23:33 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/12 15:43:46 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H

# define IMAGE_H

# include "so_long.h"

void		put_image(char **av, t_vars game);
void		get_image(t_vars *game);
void		draw_image(int x, int y, void *img, t_vars game);

#endif