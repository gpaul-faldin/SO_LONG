/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:33:25 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/19 22:39:14 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_map(t_map *map, int stage)
{
	int	i;

	i = 0;
	if (stage >= 1)
	{
		if (map->map_string)
			free(map->map_string);
		if (map->map)
		{
			while (map->map[i])
			{
				free(map->map[i]);
				i++;
			}
			free(map->map);
		}
		if (stage >= 2)
		{
			if (map->collec_pos)
				free(map->collec_pos);
			if (map->exit_pos)
				free(map->exit_pos);
		}
	}
}

static void	free_texture(t_every *info, t_texture *texture)
{
	if (texture->bear.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->bear.ptr);
	if (texture->girl.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->girl.ptr);
	if (texture->plan.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->plan.ptr);
	if (texture->lad.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->lad.ptr);
	if (texture->wall.ptr)
		mlx_destroy_image(info->mlx->mlx, texture->wall.ptr);
	if (info->mlx->mlx_win)
		mlx_destroy_window(info->mlx->mlx, info->mlx->mlx_win);
	if (info->mlx->mlx)
		free(info->mlx->mlx);
}

void	free_mem(t_every *info, char *str, int stage)
{
	if (stage >= 1)
	{
		free_map(info->map, stage);
		if (stage >= 3)
			free_texture(info, info->texture);
	}
	free(info->key);
	free(info->mlx);
	free(info->map);
	free(info->texture);
	free(info);
	if (stage < 4)
		ft_error(str);
	else
		exit(EXIT_SUCCESS);
}
