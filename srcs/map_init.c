/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 04:36:59 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/13 04:43:49 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_exist_extension(char *name)
{
	int	i;
	int	fd;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (name[i] == '\0')
	{
		ft_putstr_fd("Error\nThe file extension is not .ber\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strstr_ret_int(name, ".ber") == 1)
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("Error\nWrong map path or the map doesn't exist\n", 2);
			exit(EXIT_FAILURE);
		}
		close(fd);
		return (1);
	}
	ft_putstr_fd("Error\nThe file extension is not .ber\n", 2);
	exit(EXIT_FAILURE);
}

int	map_size(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_string[i] != '\n')
		i++;
	map->lenght = i;
	i = 0;
	while (map->map_string[i] != '\0')
	{
		if (map->map_string[i] == '\n')
			map->width++;
		i++;
	}
	return (1);
}


t_map	*map_init(char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (map == NULL)
		return (NULL);
	map->lenght = 0;
	map->width = 0;
	map->collec = 0;
	map->exit = 0;
	map->player.status = 0;
	check_exist_extension(argv[1]);
	copy_split(argv[1], map);
	map_size(map);
	check_map(map);
	map->collec_pos = malloc(sizeof(t_posi) * map->collec);
	if (map->exit > 1)
		map->exit_pos = malloc(sizeof(t_posi) * map->collec);
	return (map);
}
