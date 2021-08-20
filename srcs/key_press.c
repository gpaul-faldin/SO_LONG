/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:09:46 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/19 22:36:03 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mlx_terminate(t_every *info)
{
	free_mem(info, "", 4);
	return (0);
}

int	key_press(int keycode, t_every *info)
{
	if (keycode == 53 || keycode == 65307)
		mlx_terminate(info);
	if (keycode == 13 || keycode == 119 || keycode == 0 || keycode == 97
		|| keycode == 1 || keycode == 115 || keycode == 2 || keycode == 100)
	{
		if (keycode == 13 || keycode == 119)
			info->key->W = 1;
		else if (keycode == 0 || keycode == 97)
			info->key->A = 1;
		else if (keycode == 1 || keycode == 115)
			info->key->S = 1;
		else if (keycode == 2 || keycode == 100)
			info->key->D = 1;
	}
	return (0);
}
