/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:55:56 by gpaul             #+#    #+#             */
/*   Updated: 2020/09/03 02:27:00 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		n;

	n = 0;
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[n] && dstsize > (i + n + 1))
	{
		dst[i + n] = src[n];
		n++;
	}
	if (i != dstsize)
		dst[i + n] = '\0';
	return (i + ft_strlen(src));
}
