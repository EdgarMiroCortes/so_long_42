/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:43:42 by emiro-co          #+#    #+#             */
/*   Updated: 2023/09/06 16:06:57 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h> 
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define KEYDOWN 2
# define KEYUP 3
# define MOUSEDOWN 4
# define MOUSEUP 5
# define MOUSEMOVE 6
# define EXPOSE 12
# define DESTROY 17

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_objects
{
	void		*fruit;
	void		*dino;
	void		*floor;
	void		*wall;
	void		*door;
	void		*win;
}				t_object;

typedef struct s_point
{
	int			col;
	int			row;
}				t_point;

typedef struct s_map
{
	int			rows;
	int			cols;
	int			coins;
	char		**box;
	char		**box_for_solution;
	int			solution;
	int			format;
	int			walls;
	int			moves;
	int			finished;
	t_point		size;
	t_point		begin;
	t_point		act;
	t_point		exit;
}	t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		map;
}				t_vars;

enum {
	ON_KEYDOWN = 1,
	ON_KEYUP = 13,
	ON_KEYIZQ = 0,
	ON_KEYDER= 2,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

/* MLX UTILS */
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			closewindow_esc(int key, t_vars *vars);
int			closewindow(t_vars *vars);

/* MAP PARSING */
char		**fill_map(char *path, int size);
int			check_format(char *path);
int			count_coins(char **map);
int			check_walls(char **map, int last, int col);

/* SET SIZES */
t_point		set_size(int cols, int rows);
int			size_map_rows(char *path);
int			size_map_cols(char *path);
t_point		set_point(char **map, char c);

/* CHECK SOL */
char		**set_solution_box(char **map, int rows, int cols);
void		fill(char **tab, t_point size, t_point cur, char to_fill);
void		flood_fill(char **tab, t_point size, t_point begin);
int			check_sol(t_point exit, char **map);
int			check_all(t_map map);

/* MOVES */
int			ft_move(int key, void *map);
int			move_up(t_map *map);
int			move_down(t_map *map);
int			move_izq(t_map *map);
int			move_der(t_map *map);

/* PURE SO_LONG FUNCTIONS */
t_map		ft_readmap(char *path);
void		ft_printmap(t_map map, t_vars vars, t_object obj);
void		ft_select_img(t_vars vr, t_object obj, t_point x, t_point i);
t_object	ft_ini_objs(void *mlx);
int			ft_move(int key, void *map);
void		ft_free(t_vars *vars);

#endif