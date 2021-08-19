/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 20:08:27 by gpaul             #+#    #+#             */
/*   Updated: 2021/06/30 15:52:43 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		n;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		n = 0;
		while (needle[n] == haystack[i] && haystack[i] && needle[n] && i < len)
		{
			n++;
			i++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + (i - n));
		i = i - n;
		i++;
	}
	return (NULL);
}
