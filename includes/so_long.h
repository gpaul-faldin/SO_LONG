/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:13:08 by gpaul             #+#    #+#             */
/*   Updated: 2021/08/13 07:56:17 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
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
	GNL
*/
# define BUFFER_SIZE 5000

int		next_nl(char *str);
char	*ft_strdup_free(char **s1, int i, int size);
char	*ft_strjoin_free(char **s1, char *s2);

/*
	INIT MAP
*/
t_map	*map_init(char **argv);

/*
	UTILS
*/
int		ft_strstr_ret_int(char *str, char *to_find);

/*
	MAP PARSE
*/
int		copy_split(char *path, t_map *map);
int		check_map(t_map *map);
char	*copy(char *res, char *map_file);
int		nb_char_file(char *map_file);

/*
	ERROR
*/
int		error_in_parse(t_map *map);
void	ft_error(char *str);

/*
	TEXTURE
*/
void	texture_init(t_texture *texture, t_mlx *mlx);
void	initial_render(t_texture *texture, t_map *map, t_mlx *mlx);
int		ft_update(t_every *info);
void	update_render_init(t_texture *texture, t_map *map, t_mlx *mlx);

/*
	KEY/MOVE
*/
int		key_press(int keycode, t_key *key);
int		mlx_terminate(int keycode, t_key *key);

#endif
