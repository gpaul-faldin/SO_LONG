/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 23:45:39 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/18 21:23:28 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	texture_init(t_texture *texture, t_mlx *mlx, t_every *info)
{
	texture->bear.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/bear_plank.xpm",
			&texture->bear.width, &texture->bear.height);
	texture->girl.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/girl_plank.xpm",
			&texture->girl.width, &texture->girl.height);
	texture->plan.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/plank.xpm",
			&texture->plan.width, &texture->plan.height);
	texture->lad.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/ladder.xpm",
			&texture->lad.width, &texture->lad.height);
	texture->wall.ptr = mlx_xpm_file_to_image(mlx->mlx, "img/wall.xpm",
			&texture->wall.width, &texture->wall.height);
	if (texture->bear.ptr == NULL || texture->girl.ptr == NULL
		|| texture->plan.ptr == NULL || texture->lad.ptr == NULL
		|| texture->wall.ptr == NULL)
		free_mem(info, "Error\nError while allocating memory\n", 3);
	texture->bear.addr = mlx_get_data_addr(texture->bear.ptr,
			&texture->bear.bpp, &texture->bear.linelen, &texture->bear.endian);
	texture->girl.addr = mlx_get_data_addr(texture->girl.ptr,
			&texture->girl.bpp, &texture->girl.linelen, &texture->girl.endian);
	texture->plan.addr = mlx_get_data_addr(texture->plan.ptr,
			&texture->plan.bpp, &texture->plan.linelen,
			&texture->plan.endian);
	texture->lad.addr = mlx_get_data_addr(texture->lad.ptr,
			&texture->lad.bpp, &texture->lad.linelen, &texture->lad.endian);
	texture->wall.addr = mlx_get_data_addr(texture->wall.ptr,
			&texture->wall.bpp, &texture->wall.linelen, &texture->wall.endian);
}
