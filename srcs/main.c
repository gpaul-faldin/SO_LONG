/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:22:37 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/18 21:16:40 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(char *str)
{
	write(1, "[so_long] ", 10);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

static t_every	*ft_init_info(void)
{
	t_every		*info;

	info = malloc(sizeof(t_every) * 1);
	if (info == NULL)
		ft_error("Error\nError while allocating memory");
	info->mlx = malloc(sizeof(t_mlx) * 1);
	info->texture = malloc(sizeof(t_texture) * 1);
	info->key = malloc(sizeof(t_key) * 1);
	info->map = malloc(sizeof(t_map) * 1);
	if (info->key == NULL || info->mlx == NULL || info->texture == NULL
		|| info->map == NULL)
		free_mem(info, "Error\nError while allocating memory", 0);
	return (info);
}

int	main(int argc, char **argv)
{
	t_every		*info;

	if (argc != 2)
		ft_error("Error\nYou need 2 arguments.\n");
	else
	{
		info = ft_init_info();
		info->map = map_init(argv, info->map, info);
		info->mlx->mlx = mlx_init();
		info->mlx->mlx_win = mlx_new_window(info->mlx->mlx,
				(info->map->lenght * 32),
				(info->map->width * 32), "So Long");
		texture_init(info->texture, info->mlx, info);
		initial_render(info->texture, info->map, info->mlx, info);
		info->key->nbr_press = 0;
		mlx_do_key_autorepeatoff(info->mlx->mlx);
		mlx_hook(info->mlx->mlx_win, 2, 1L << 0, key_press, info->key);
		mlx_hook(info->mlx->mlx_win, 17, 1L << 17, mlx_terminate, info);
		mlx_loop_hook(info->mlx->mlx, ft_update, info);
		mlx_loop(info->mlx->mlx);
		return (0);
	}
}
