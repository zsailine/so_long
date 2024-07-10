/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:42:21 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/10 16:19:51 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	t_map	*size;

	if (ac == 2)
	{
		size = final_check(av[1]);
		if (size == NULL)
			exit(EXIT_FAILURE);
		char	*relative_path = "assets/luffy-f.xpm";
		int		img_width = 0;
		int		img_height = 0;
		vars.width = (get_map_rect(av[1]) - 1) * 50;
		vars.height = (get_map_size(av[1]) - 1) * 50;
		vars = init_game(vars);
		vars.img =  mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
		vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 50, 50);
		hook_game(vars);
	}
	ft_printf("Error\nWrong param\n");
	return (0);
}
