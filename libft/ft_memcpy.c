/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:41:14 by gpaul             #+#    #+#             */
/*   Updated: 2021/06/30 16:02:22 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*de;
	char	*s;
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	de = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		de[i] = s[i];
		i++;
	}
	return ((void *)de);
}
