/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 04:36:59 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/19 22:52:48 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_exist_extension(char *name, t_every *info)
{
	int		i;
	int		fd;
	char	buf;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	if (name[i] == '\0')
		free_mem(info, "Error\nThe file extension is not a .ber\n", 0);
	if (ft_strstr_ret_int(name, ".ber") == 1)
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
			free_mem(info, "Error\nWrong map path or the map doesn't exist\n", 0);
		if (read(fd, &buf, 1) == -1)
			free_mem(info, "Error\nThe map is a directory\n", 0);
		close(fd);
		return (1);
	}
	free_mem(info, "Error\nThe file extension is not .ber\n", 0);
	exit(EXIT_FAILURE);
}

static int	map_size(t_map *map)
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

t_map	*map_init(char **argv, t_map *map, t_every *info)
{
	map->lenght = 0;
	map->width = 0;
	map->collec = 0;
	map->exit = 0;
	map->player.status = 0;
	check_exist_extension(argv[1], info);
	copy_split(argv[1], map, info);
	map_size(map);
	check_map(map, info);
	map->collec_pos = malloc(sizeof(t_posi) * map->collec);
	map->exit_pos = malloc(sizeof(t_posi) * map->exit);
	if (map->collec_pos == NULL || map->exit_pos == NULL)
		free_mem(info, "Error\nError while allocating memory", 2);
	return (map);
}
