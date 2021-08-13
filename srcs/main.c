/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:22:37 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/13 06:15:54 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{

	t_every		*info;

	info = malloc(sizeof(t_every) * 1);
	if (info == NULL)
		exit(EXIT_FAILURE);
	info->mlx = malloc(sizeof(t_mlx) * 1);
	info->texture = malloc(sizeof(t_texture) * 1);
	info->key = malloc(sizeof(t_key) * 1);
	if (info->key == NULL || info->mlx == NULL || info->texture == NULL)
		exit(EXIT_FAILURE);

	if (argc != 2)
		ft_putstr_fd("Error\nYou need 2 arguments.\n", 2);
	else
	{
		info->map = map_init(argv);
		info->mlx->mlx = mlx_init();
		texture_init(info->texture, info->mlx);
		info->mlx->mlx_win = mlx_new_window(info->mlx->mlx, (info->map->lenght * 32),
				(info->map->width * 32), "So Long");
		initial_render(info->texture, info->map, info->mlx);
		info->key->nbr_press = 0;
		mlx_do_key_autorepeatoff(info->mlx->mlx);
		mlx_hook(info->mlx->mlx_win, 2, 1L<<0, key_press, info->key);
		mlx_hook(info->mlx->mlx_win, 17, 1L << 17, mlx_terminate, info->key);

		mlx_loop_hook(info->mlx->mlx, ft_update, info);
		mlx_loop(info->mlx->mlx);

		free(info->map->map);
		free(info->map->map_string);
		free(info->map);
		free(info->map->collec_pos);
		if (info->map->exit > 1)
			free(info->map->exit_pos);
		free(info->texture);
		free(info->mlx);
	}
}
