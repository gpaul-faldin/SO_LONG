/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:09:35 by gpaul             #+#    #+#             */
/*   Updated: 2021/06/30 16:11:23 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*re;
	char	*str;
	size_t	i;

	i = 0;
	re = malloc(size * count);
	if (re == NULL)
		return (NULL);
	str = (char *)re;
	while (i <= size * count)
	{
		str[i] = '\0';
		i++;
	}
	return (re);
}
