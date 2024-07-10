/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:11:25 by zsailine          #+#    #+#             */
/*   Updated: 2024/07/10 09:42:35 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] != '\0' || (unsigned char)s2[i] != '\0')
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		s1++;
		s2++;
	}
	return (0);
}

void	free_tab(char **stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		free(stock[i]);
		i++;
	}
	free(stock);
}
