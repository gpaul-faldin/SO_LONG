/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:14:40 by gpaul             #+#    #+#             */
/*   Updated: 2021/07/07 03:36:42 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return_strdup(char *re)
{
	if (re[0])
		return (re);
	else
		return (0);
}

char	*ft_strdup_free(char **s1, int i, int size)
{
	char	*re;
	int		n;

	n = 0;
	if (next_nl(*s1) == 0)
		size++;
	if (size <= i)
	{
		free(*s1);
		*s1 = NULL;
		return (0);
	}
	re = malloc(sizeof(char) * (size + 1));
	if (re == NULL)
		return (NULL);
	while (i < size && *(*s1 + i))
	{
		re[n] = *(*s1 + i);
		i++;
		n++;
	}
	re[n] = '\0';
	free(*s1);
	*s1 = NULL;
	return (re);
}

char	*ft_strjoin_utils(char **s1, char *s2, char *re)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < ft_strlen(*s1))
	{
		re[i] = (*s1)[i];
		i++;
	}
	while (n < ft_strlen(s2))
	{
		re[i + n] = s2[n];
		n++;
	}
	re[i + n] = '\0';
	return (re);
}

char	*ft_strjoin_free(char **s1, char *s2)
{
	char	*re;

	re = malloc(sizeof(char) * ((ft_strlen(*s1) + ft_strlen(s2)) + 1));
	if (re == NULL)
		return (0);
	re = ft_strjoin_utils(s1, s2, re);
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (re);
}
