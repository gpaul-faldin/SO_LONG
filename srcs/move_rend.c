/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 05:40:52 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/13 07:56:53 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_change_map(int Y, int X, t_every *info)
{
	int	X_p;
	int	Y_p;

	X_p = info->map->player.X;
	Y_p = info->map->player.Y;
	info->map->map[Y][X] = 'P';
	info->map->map[Y_p][X_p] = '0';
	info->map->player.Y = Y;
	info->map->player.X = X;
	info->key->nbr_press += 1;
	printf("current number of movements : %d\n", info->key->nbr_press);
}

static int	ft_check_event(t_every *info, int X, int Y, char **map)
{
	int	i;

	i = 0;
	if (map[Y][X] == 'C')
	{
		while (i < info->map->collec)
		{
			if (Y == info->map->collec_pos[i].Y
				&& X == info->map->collec_pos[i].X)
				info->map->collec_pos[i].status = 0;
			i++;
		}
	}
	else if (map[Y][X] == 'E')
	{
		while (i < info->map->collec)
		{
			if (info->map->collec_pos[i].status == 1)
				return (1);
			i++;
		}
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static void	ft_move_init2(t_every *info, int Y_p, int X_p)
{
	if (info->key->A == 1)
	{
		if (ft_check_event(info, X_p - 1, Y_p, info->map->map) == 0
			&& info->map->map[Y_p][X_p - 1] != '1')
			ft_change_map(Y_p, X_p - 1, info);
		info->key->A = 0;
	}
	else if (info->key->D == 1)
	{
		if (ft_check_event(info, X_p + 1, Y_p, info->map->map) == 0
			&& info->map->map[Y_p][X_p + 1] != '1')
			ft_change_map(Y_p, X_p + 1, info);
		info->key->D = 0;
	}
}

static void	ft_move_init(t_every *info, int X_p, int Y_p)
{
	if (info->key->W == 1)
	{
		if (ft_check_event(info, X_p, Y_p - 1, info->map->map) == 0
			&& info->map->map[Y_p - 1][X_p] != '1')
			ft_change_map(Y_p - 1, X_p, info);
		info->key->W = 0;
	}
	else if (info->key->S == 1)
	{
		if (ft_check_event(info, X_p, Y_p + 1, info->map->map) == 0
			&& info->map->map[Y_p + 1][X_p] != '1')
			ft_change_map(Y_p + 1, X_p, info);
		info->key->S = 0;
	}
	else
		ft_move_init2(info, Y_p, X_p);
}

int	ft_update(t_every *info)
{
	ft_move_init(info, info->map->player.X, info->map->player.Y);
	update_render_init(info->texture, info->map, info->mlx);
	return (0);
}
