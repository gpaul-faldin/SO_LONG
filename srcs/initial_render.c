/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 03:16:15 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/13 04:45:35 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	info_initial_render(t_map *map, t_coo *coo)
{
	if (map->map[coo->n][coo->i] == 'P')
	{
		map->player.X = coo->X / 32;
		map->player.Y = coo->Y / 32;
	}
	else if (map->map[coo->n][coo->i] == 'E')
	{
		map->exit_pos[coo->exi].X = coo->X / 32;
		map->exit_pos[coo->exi].Y = coo->Y / 32;
		map->exit_pos[coo->exi].status = 1;
		coo->exi += 1;
	}
	else if (map->map[coo->n][coo->i] == 'C')
	{
		map->collec_pos[coo->coll].X = coo->X / 32;
		map->collec_pos[coo->coll].Y = coo->Y / 32;
		map->collec_pos[coo->coll].status = 1;
		coo->coll += 1;
	}
}

static void	put_initial_render(t_texture *texture, t_map *map, t_mlx *mlx,
	t_coo *coo)
{
	if (map->map[coo->n][coo->i] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->wall.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->plan.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->girl.ptr, coo->X, coo->Y);
		info_initial_render(map, coo);
	}
	else if (map->map[coo->n][coo->i] == 'E')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->lad.ptr, coo->X, coo->Y);
		info_initial_render(map, coo);
	}
	else if (map->map[coo->n][coo->i] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->bear.ptr, coo->X, coo->Y);
		info_initial_render(map, coo);
	}
}

void	initial_render(t_texture *texture, t_map *map, t_mlx *mlx)
{
	t_coo	*coo;

	coo = malloc(sizeof(t_coo) * 1);
	if (coo == NULL)
		ft_error("error while assigning memory");
	coo->i = 0;
	coo->n = 0;
	coo->X = 0;
	coo->Y = 0;
	coo->coll = 0;
	coo->exi = 0;
	while (map->map[coo->n])
	{
		while (map->map[coo->n][coo->i])
		{
			put_initial_render(texture, map, mlx, coo);
			coo->i++;
			coo->X = coo->X + 32;
		}
		coo->n++;
		coo->i = 0;
		coo->X = 0;
		coo->Y = coo->Y + 32;
	}
	free(coo);
}
