/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:22:38 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/19 20:34:39 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_sep(char c, char str)
{
	if (c == str)
		return (1);
	else
		return (0);
}

static int	ft_count_word(char *str, char c)
{
	int	i;
	int	words;
	int	n;

	i = 0;
	words = 0;
	while (str[i])
	{
		n = 0;
		while (str[i] && ft_sep(c, str[i]) == 1)
			i++;
		while (str[i] && ft_sep(c, str[i]) == 0 && ++n)
			i++;
		if (n > 0)
			words++;
	}
	return (words);
}

static char	**ft_mem(char *str, char c, char **re)
{
	int	i;
	int	x;
	int	n;

	i = 0;
	x = 0;
	while (str[i])
	{
		n = 0;
		while (str[i] && ft_sep(c, str[i]) == 1)
			i++;
		while (str[i] && ft_sep(c, str[i]) == 0 && ++n)
			i++;
		if (n > 0)
		{
			re[x] = malloc(sizeof(char) * (n + 1));
			if (re == NULL)
				return (0);
		}
		x++;
	}
	return (re);
}

static char	**ft_alloc(char *str, char c, char **re, int i)
{
	int	y;
	int	x;
	int	n;

	y = 0;
	while (str[i])
	{
		x = 0;
		n = 0;
		while (str[i] && ft_sep(c, str[i]) == 1)
			i++;
		while (str[i] && ft_sep(c, str[i]) == 0 && ++n)
			i++;
		while (n > x)
		{
			re[y][x] = str[i - (n - x)];
			x++;
		}
		if (n > 0)
			re[y][x] = '\0';
		y++;
	}
	return (re);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	int		i;
	char	**re;

	i = 0;
	if (s == (void *)0)
		return (0);
	str = (char *)s;
	re = malloc(sizeof(char *) * (ft_count_word(str, c) + 1));
	if (re == NULL)
		return (0);
	if (ft_count_word(str, c) > 0)
	{
		re = ft_mem(str, c, re);
		re = ft_alloc(str, c, re, i);
	}
	re[ft_count_word(str, c)] = 0;
	return (re);
}
