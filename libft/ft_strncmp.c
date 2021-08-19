/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:47:19 by gpaul             #+#    #+#             */
/*   Updated: 2021/06/30 16:07:27 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*str_1;
	char	*str_2;
	size_t	i;

	str_1 = (char *)s1;
	str_2 = (char *)s2;
	i = 0;
	while (i < n && (str_1[i] || str_2[i]))
	{
		if (str_1[i] != str_2[i])
			return ((int)((unsigned char)str_1[i] - (unsigned char)str_2[i]));
		i++;
	}
	return (0);
}
