/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:43:42 by emiro-co          #+#    #+#             */
/*   Updated: 2023/08/23 17:50:13 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include "../mlx/mlx.h"
#include "../libft/libft.h"

//FLAGS    := -Lmlx -lmlx -framework OpenGL -framework AppKit

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

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
	t_point		begin;
}	t_map;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//int		close(int keycode, t_vars *vars);
t_map	ft_readmap(char *path);
char	**fill_map(char *path, int size);
int		size_map_rows(char *path);
int		size_map_cols(char *path);
int		check_format(char *path);
int		count_coins(char **map);
int		check_walls(char **map, int last, int col);
t_point	set_begin(char **map);

//flood fill
int		flood_fill(char **map, t_point size, t_point begin);
int		fill(char **map, t_point size, t_point cur, char to_fill);








