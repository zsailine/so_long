/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:37:48 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/16 14:01:25 by zsailine         ###   ########.fr       */
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
		ft_putendl_fd("Oh no Zorro get lost again!", 1);
		ft_putendl_fd("Help him go back to his universe.", 1);
		game.width = (get_map_rect(av[1]) - 1) * 50;
		game.height = (get_map_size(av[1])) * 50;
		game = init_game1(game);
		get_image1(&game);
		put_image1(&game);
		hook_game1(game);
	}
	ft_putendl_fd("Error\nWrong param", 2);
	return (0);
}
