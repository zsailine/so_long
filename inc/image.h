/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:23:33 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 13:04:20 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H

# define IMAGE_H

# include "so_long.h"

void	put_image(t_vars *game);
void	get_image(t_vars *game);
void	draw_image(int x, int y, void *img, t_vars *game);
void	draw_image1(int x, int y, void *img, t_vars *game);
void	draw_katana(int j, int i, t_vars *game);
void	draw_player1(int j, int i, t_vars *game, int check);
void	get_image1(t_vars *game);
void	put_image1(t_vars *game);

#endif