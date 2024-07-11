/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:42:21 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/11 16:09:58 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int ac, char **av)
{
	t_vars	game;

	if (ac == 2)
	{
		game.map = final_check(av[1]);
		if (game.map == NULL)
			exit(EXIT_FAILURE);
		game.width = (get_map_rect(av[1]) - 1) * 50;
		game.height = (get_map_size(av[1]) - 1) * 50;
		game = init_game(game);
		put_image(game.map->map, game);
		hook_game(game);
	}
	ft_putendl_fd("Error\nWrong param\n", 2);
	return (0);
}
