/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:09:46 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/13 07:56:59 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	mlx_terminate(int keycode, t_key *key)
{
	(void)keycode;
	(void)key;
	exit(0);
	return (0);
}

int	key_press(int keycode, t_key *key)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		if (keycode == 13)
			key->W = 1;
		else if (keycode == 0)
			key->A = 1;
		else if (keycode == 1)
			key->S = 1;
		else if (keycode == 2)
			key->D = 1;
	}
	return (0);
}
