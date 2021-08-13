/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 03:09:39 by gpaul             #+#    #+#             */
/*   Updated: 2021/06/30 16:02:40 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*str;
	int				x;

	x = 0;
	dst = (unsigned char *)dest;
	str = (unsigned char *)src;
	i = 0;
	while (i < n && x == 0)
	{
		if (str[i] == (unsigned char)c)
			x = i + 1;
		dst[i] = str[i];
		i++;
	}
	if (x == 0)
		return (NULL);
	else
		return ((void *)dst + x);
}
