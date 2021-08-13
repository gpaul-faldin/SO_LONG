/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:22:37 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/13 04:46:46 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_texture	*texture;
	t_mlx		*mlx;

	if (argc != 2)
		ft_putstr_fd("Error\nYou need 2 arguments.\n", 2);
	else
	{
		map = map_init(argv);
		mlx = malloc(sizeof(t_mlx) * 1);
		texture = malloc(sizeof(t_texture) * 1);
		mlx->mlx = mlx_init();
		texture_init(texture, mlx);
		mlx->mlx_win = mlx_new_window(mlx->mlx, (map->lenght * 32),
				(map->width * 32), "So Long");
		initial_render(texture, map, mlx);

		

		mlx_loop(mlx->mlx);
		free(map->map);
		free(map->map_string);
		free(map);
		free(map->collec_pos);
		if (map->exit > 1)
			free(map->exit_pos);
		free(texture);
		free(mlx);
	}
}
