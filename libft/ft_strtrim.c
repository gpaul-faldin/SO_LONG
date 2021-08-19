/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:29:39 by gpaul             #+#    #+#             */
/*   Updated: 2021/06/30 16:28:41 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sep(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_lenght(char *s1_cp, char *charset)
{
	int		i;
	int		n;
	int		size;

	i = ft_strlen(s1_cp) - 1;
	n = 0;
	size = 0;
	while (ft_sep(s1_cp[i], charset) == 1)
		i--;
	while (ft_sep(s1_cp[n], charset) == 1)
		n++;
	size = (i + 1) - n;
	return (size);
}

static char	*ft_alloc(char *str, char *s1_cp, char *charset)
{
	int		i;
	int		n;
	int		x;

	x = 0;
	n = 0;
	i = ft_strlen(s1_cp) - 1;
	while (ft_sep(s1_cp[n], charset) == 1)
		n++;
	while (ft_sep(s1_cp[i], charset) == 1)
		i--;
	while (n <= i)
	{
		str[x] = s1_cp[n];
		n++;
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*s1_cp;
	char	*charset;

	if (s1 == (void *)0)
		return ("0");
	s1_cp = (char *)s1;
	charset = (char *)set;
	if (ft_lenght(s1_cp, charset) > 0)
	{
		str = malloc(sizeof(char) * ((ft_lenght(s1_cp, charset) + 1)));
		if (str == NULL)
			return (NULL);
	}
	if (ft_lenght(s1_cp, charset) < 0)
	{
		str = malloc(sizeof(char) * (1 + 1));
		if (str == NULL)
			return (NULL);
	}
	str = ft_alloc(str, s1_cp, charset);
	return (str);
}
