/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:13:15 by ajacome-          #+#    #+#             */
/*   Updated: 2023/04/18 16:24:24 by aguerri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# define BUF_SIZE 4096
# define CORRECT 0

enum e_error_types
{
	input,
	parse,
};

typedef enum e_status
{
	error,
	ok,
}	t_status;

typedef struct s_coordinates
{
	int x;
	int y;
}	t_coord;

typedef struct s_limits
{
	t_coord from;
	t_coord to;
}	t_limits;

typedef struct s_count
{
	int	lines;
	int cols;
}	t_count;

typedef struct s_map
{
	int			lines;
	char		empty;
	char		obstacle;
	char		full;
	int			columns;
	int			obs_qty;
	t_coord		*obs;
	t_status	status;
	char		**box;
}	t_map;

char		**read_stdin(int *len);
char		**read_maps(int argc, char **files, int *map_qty);
int			get_file_size(char *path);
char		**read_files(int file_qty, char **files, int *map_qty);
char		*read_file_content(char *path, int size);
t_map		*parse_maps(int map_q, char **maps_str);
t_status	parse_map(char *map_str, t_map *map);
int			get_end_of_line(char *str);
t_status	get_keys(char *map_str, t_map *map);
t_status	verify_key_chars(t_map *map);
t_status	char_is_printable(char c);
t_status	get_map_lines(char *map_str, int i, t_map *map);
t_status	is_valid_char(char c, t_map *map);
t_status	verify_ln_size(t_map *map, int count);
void		initialize_matrix(t_map *map, int line);
t_status	fill_matrix(char c, t_map *map, t_count *count);
void	count_obstacle(char c, t_map *map);
void	fill_obs_cord(t_map *map);
void	get_obs_coord(t_map *maps, int map_q);

int			ft_charcmp(char str, char *charset);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size, int *pos);
int		ft_strlen_charset(char *str, char *charset, int *i);
int		ft_size(char *str, char *charset);
char	**ft_split(char *str, char *charset, int *map_qty);
void 	ft_putstrerror (char *str);
int 	ft_check_map(char *map);
int 	ft_check_lines(char **lines, t_map *map);
char	*read_file_content(char *path, int size);
int		get_file_size(char *path);
char	**ft_check_stdin(char **arguments, char **content, int len);
char	**ft_check_argv(char **argv, char **content, int argc);
char	**read_argv(int argc, char **argv);


#endif
