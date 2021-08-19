/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 04:21:13 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/19 21:08:20 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	nb_char_file(char *map_file)
{
	int		fd;
	char	buf;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((read(fd, &buf, 1)))
		i++;
	close(fd);
	return (i);
}

static int	*copy(char *res, char *map_file)
{
	int		fd;
	char	buf;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((read(fd, &buf, 1)))
	{
		res[i] = buf;
		i++;
	}
	res[i] = '\0';
	close(fd);
	return (0);
}

int	copy_split(char *path, t_map *map, t_every *info)
{
	map->map_string = malloc(sizeof(char) * nb_char_file(path) + 1);
	if (map->map_string == NULL)
		free_mem(info, "Error\nError while allocating memory", 0);
	copy(map->map_string, path);
	map->map = ft_split(map->map_string, '\n');
	if (map->map == NULL)
	{
		free(map->map_string);
		free_mem(info, "Error\nError while allocating memory", 0);
	}
	return (1);
}
