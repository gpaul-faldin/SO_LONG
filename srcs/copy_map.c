/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 04:21:13 by gpaul             #+#    #+#             */
/*   Updated: 2021/07/07 04:59:32 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	nb_char_file(char *map_file)
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

char	*copy(char *res, char *map_file)
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
	return (res);
}

int	copy_split(char *path, t_map *map)
{
	map->map_string = malloc(sizeof(char) * nb_char_file(path));
	if (map->map_string == NULL)
		return (-1);
	copy(map->map_string, path);
	map->map = ft_split(map->map_string, '\n');
	if (map->map == NULL)
		return (-1);
	return (1);
}
