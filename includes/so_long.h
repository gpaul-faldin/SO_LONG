/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:13:08 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/19 22:36:08 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_texture
{
	t_img	plan;
	t_img	bear;
	t_img	girl;
	t_img	lad;
	t_img	wall;

}				t_texture;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;

}				t_mlx;

typedef struct s_posi
{
	int		status;
	int		X;
	int		Y;

}				t_posi;

typedef struct s_map
{
	char	*map_string;
	char	**map;
	int		lenght;
	int		width;
	int		collec;
	int		exit;
	t_posi	*collec_pos;
	t_posi	*exit_pos;
	t_posi	player;
}				t_map;

typedef struct s_coo
{
	int		n;
	int		i;
	int		X;
	int		Y;
	int		coll;
	int		exi;
}				t_coo;

typedef struct s_key
{
	int		W;
	int		A;
	int		S;
	int		D;
	int		ESC;
	int		nbr_press;
}				t_key;

typedef struct s_every
{
	t_map		*map;
	t_texture	*texture;
	t_mlx		*mlx;
	t_key		*key;
}				t_every;

/*
	INIT MAP
*/
t_map	*map_init(char **argv, t_map *map, t_every *info);

/*
	UTILS
*/
int		ft_strstr_ret_int(char *str, char *to_find);

/*
	MAP PARSE
*/
int		copy_split(char *path, t_map *map, t_every *info);
int		check_map(t_map *map, t_every *info);

/*
	ERROR
*/
int		error_in_parse(t_map *map);
void	ft_error(char *str);
void	free_mem(t_every *info, char *str, int stage);

/*
	TEXTURE
*/
void	texture_init(t_texture *texture, t_mlx *mlx, t_every *info);
void	initial_render(t_texture *texture, t_map *map, t_mlx *mlx,
			t_every *info);
int		ft_update(t_every *info);
void	update_render_init(t_texture *texture, t_map *map, t_mlx *mlx,
			t_every *info);

/*
	KEY/MOVE
*/
int		key_press(int keycode, t_every *info);
int		mlx_terminate(t_every *info);

#endif
