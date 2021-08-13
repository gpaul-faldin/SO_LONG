/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:14:41 by gpaul             #+#    #+#             */
/*   Updated: 2021/07/30 00:19:46 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	next_nl(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

void	ft_fill_line(char **cache, char **line)
{
	int		i;
	int		size;

	i = 0;
	if (next_nl(*cache) > 0)
		size = next_nl(*cache);
	else
		size = ft_strlen(*cache);
	*line = malloc(sizeof(char) * size + 1);
	if (*line == NULL)
		return ;
	while (i < size)
	{
		*((*line) + i) = *((*cache) + i);
		i++;
	}
	if (size > 0)
		size--;
	*((*line) + size) = '\0';
	*cache = ft_strdup_free(cache, next_nl(*cache), ft_strlen(*cache));
}

int	ft_return(char **cache, int re, char **line, char *buf)
{
	if (re >= 0)
	{
		buf[re] = '\0';
		*cache = ft_strjoin_free(cache, buf);
		if (next_nl(*cache) == 0)
		{
			*line = ft_strdup_free(cache, 0, ft_strlen(*cache));
			return (0);
		}
	}
	ft_fill_line(cache, line);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		*cache[4096];
	char			buf[BUFFER_SIZE + 1];
	int				re;

	re = 1;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (next_nl(cache[fd]) > 0)
	{
		ft_fill_line(&cache[fd], line);
		return (1);
	}
	while (re != 0)
	{
		re = read(fd, buf, BUFFER_SIZE);
		buf[re] = '\0';
		cache[fd] = ft_strjoin_free(&cache[fd], buf);
		if (next_nl(buf) > 0)
		{
			ft_fill_line(&cache[fd], line);
			return (1);
		}
	}
	return (ft_return(&cache[fd], re, line, buf));
}
