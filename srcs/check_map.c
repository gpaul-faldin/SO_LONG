/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 05:02:04 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/13 04:42:48 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_letters(t_map *map, int cpy_width, int i)
{
	if ((cpy_width == map->width - 1 || cpy_width == 0)
		&& map->map[cpy_width][i] != '1')
		return (error_in_parse(map));
	else if ((i == 0 || i == map->lenght - 1)
		&& map->map[cpy_width][i] != '1')
		return (error_in_parse(map));
	else if (map->map[cpy_width][i] == 'C')
		map->collec++;
	else if (map->map[cpy_width][i] == 'E')
		map->exit++;
	else if (map->map[cpy_width][i] == 'P')
		map->player.status++;
	else if (map->map[cpy_width][i] == '0' || map->map[cpy_width][i] == '1')
		return (0);
	else
		return (-1);
	return (0);
}

int	check_map(t_map *map)
{
	int	cpy_width;
	int	i;

	if (map->width == map->lenght)
		return (error_in_parse(map));
	cpy_width = map->width - 1;
	while (cpy_width != -1)
	{
		i = 0;
		while (map->map[cpy_width][i])
		{
			if (check_letters(map, cpy_width, i) == -1)
				return (error_in_parse(map));
			i++;
		}
		cpy_width--;
	}
	if (map->collec != 0 && map->exit != 0 && map->player.status != 0)
		return (1);
	else
		return (error_in_parse(map));
}
