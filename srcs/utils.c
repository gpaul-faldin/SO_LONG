/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:46:19 by gpaul             #+#    #+#             */
/*   Updated: 2021/07/07 04:44:46 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strstr_ret_int(char *str, char *to_find)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == to_find[n] && to_find[n])
		{
			i++;
			n++;
		}
		if (to_find[n] == '\0' && str[i] == '\0')
			return (1);
		else
		{
			i = i - n;
			n = 0;
		}
		i++;
	}
	return (0);
}
