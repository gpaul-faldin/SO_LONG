/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 22:42:20 by gpaul             #+#    #+#             */
/*   Updated: 2021/06/30 16:29:25 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rev(char *re, int index)
{
	int		i;
	int		n;
	char	temp;

	re[index] = '\0';
	i = 0;
	n = ft_strlen(re);
	while (i < n)
	{
		n--;
		temp = re[i];
		re[i] = re[n];
		re[n] = temp;
		i++;
	}
	return (re);
}

static char	*ft_zero(char *re)
{
	re[0] = '0';
	re[1] = '\0';
	return (re);
}

static int	size_count(int n)
{
	int		res;

	res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res + 1);
}

char	*ft_itoa(int n)
{
	char	*re;
	int		i;
	int		signe;
	long	nb;

	nb = n;
	i = 0;
	signe = 0;
	re = malloc(sizeof(char) * size_count(n) + 1);
	if (re == NULL)
		return (0);
	if (nb == 0)
		return (ft_zero(re));
	if (nb < 0)
		signe = 1;
	if (signe == 1)
		nb = -nb;
	while (nb > 0)
	{
		re[i++] = ((nb % 10) + '0');
		nb = nb / 10;
	}
	if (signe == 1)
		re[i++] = '-';
	return (ft_rev(re, i));
}
