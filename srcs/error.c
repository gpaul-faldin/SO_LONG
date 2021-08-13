/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 05:32:13 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/13 02:43:35 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_map_map(t_map *map)
{
	int	cpy_width;

	cpy_width = map->width - 1;
	while (cpy_width != -1)
	{
		free(map->map[cpy_width]);
		cpy_width--;
	}
	return (0);
}

int	error_in_parse(t_map *map)
{
	free_map_map(map);
	free(map->map);
	free(map->map_string);
	free(map);
	ft_putstr_fd("Error\nYour map is invalid\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error(char *str)
{
	write(1, "[so_long] ", 10);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
