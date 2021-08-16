/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_rend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 06:37:26 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/16 02:51:10 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_render(t_texture *texture, t_map *map, t_mlx *mlx,
	t_coo *coo)
{
	if (map->map[coo->n][coo->i] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->wall.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->plan.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->girl.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->lad.ptr, coo->X, coo->Y);
	else if (map->map[coo->n][coo->i] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			texture->bear.ptr, coo->X, coo->Y);
}

void	update_render_init(t_texture *texture, t_map *map, t_mlx *mlx)
{
	t_coo	*coo;

	coo = malloc(sizeof(t_coo) * 1);
	if (coo == NULL)
		ft_error("Error\nError while allocating memory");
	coo->i = 0;
	coo->n = 0;
	coo->X = 0;
	coo->Y = 0;
	while (map->map[coo->n])
	{
		while (map->map[coo->n][coo->i])
		{
			update_render(texture, map, mlx, coo);
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
