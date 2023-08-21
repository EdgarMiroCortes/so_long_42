#include "includes.h"

int	main(int argc, char **argv)
{
	char	**maps_str;
	t_map	*maps;
	int		map_qty;

	maps_str = read_maps(argc, argv, &map_qty);
	// printf("%s\n", maps_str[0]);
	// write(1, maps_str, 79);
	// printf("%s\n", maps_str[1]);
	maps = parse_maps(map_qty, maps_str);

	// printf("%s\n", maps[0].box[0]);
	// printf("sali:\n");
	// process(&maps);
	for (int k = 0; k < 2; k++)
	{
		for (int j = 0; j < 5; j++)
		{
			write(1, maps[k].box[j], 6);
			write(1, "\n", 1);
		}
		printf("\nnuevo archivo\n");
	}
	return (0);
}


t_map	*parse_maps(int map_q, char **maps_str)
{
	int		i;
	t_map	*maps;

	i = 0;
	maps = (t_map *) malloc(sizeof(t_map) * map_q);
	
	while (i < map_q)
	{
		parse_map(maps_str[i], (maps + i));
		i++;
	}
	get_obs_coord(maps, map_q);
	return (maps);
}

t_status	parse_map(char *map_str, t_map *map)
{
	int		i;
	t_count	count;

	count.lines = 0;
	count.cols = 0;
	if (!get_keys(map_str, map))
		return (error);
	map->box = (char **) malloc(sizeof(char *) * map->lines);
	if (!map->box)
		exit(error);
	i = get_end_of_line(map_str) + 1;
	while (map_str[i])
	{
		if (count.cols == 0)
			initialize_matrix(map, count.lines);
		if (!fill_matrix(map_str[i], map, &count))
			return (error);
		i++;
	}
	if (!verify_ln_size(map, count.lines))
		return (error);
	return (ok);
}

void	count_obstacle(char c, t_map *map)
{
	if (c == map->obstacle)
		map->obs_qty += 1;
}

void	get_obs_coord(t_map *maps, int map_q)
{
	int	k;

	k = 0;
	while (k < map_q)
	{
		maps[k].obs = (t_coord *)malloc(sizeof(t_coord) * maps[k].obs_qty);
		fill_obs_cord((maps + k));
		k++;
	}
}

void	fill_obs_cord(t_map *map)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (j < map->lines)
	{
		i = 0;
		while (i < map->columns)
		{
			if (map->box[j][i] == map->obstacle)
			{
				map->obs[k].x = i;
				map->obs[k].y = j;
				k++;
			}
			i++;
		}
		j++;
	}
}

t_status	fill_matrix(char c, t_map *map, t_count *count)
{
	if ((c == '\n' || c == '\0' )&& count->cols == map->columns)
	{
		count->cols = 0;
		count->lines++;
		return (ok);
	}
	else if (c == '\n')
	{
		map->status = error;
		return (error);
	}
	count_obstacle(c, map);
	map->box[count->lines][count->cols] = c;
	count->cols += 1;
	if (!is_valid_char(c, map))
		return (error);
	return (ok);
}

t_status	is_valid_char(char c, t_map *map)
{
	if (c == map->empty || c == map->obstacle)
		return (ok);
	map->status = error;
	return (error);
}
t_status	verify_ln_size(t_map *map, int count)
{
	if (count != map->lines)
	{
		map->status = error;
		return (error);
	}
	return (ok);
}

void	initialize_matrix(t_map *map, int line)
{
	map->box[line] = (char *) malloc(sizeof(char) * map->columns);
	if (!map->box[line])
		exit(error);
}

t_status	get_keys(char *map_str, t_map *map)
{
	int	i;

	i = get_end_of_line(map_str);
	map->columns = get_end_of_line((map_str + i + 1));
	if (map->columns == 0)
	{
		map->status = error;
		return (error);
	}
	map->full = map_str[--i];
	map->obstacle = map_str[--i];
	map->empty = map_str[--i];
	if (!verify_key_chars(map))
		return (error);
	if (!get_map_lines(map_str, i, map))
		return (error);
	return (ok);
}

t_status	verify_key_chars(t_map *map)
{
	if (map->full == map->obstacle || map->full == map->empty
		|| map->obstacle == map->empty)
	{
		map->status = error;
		return (error);
	}
	if (!char_is_printable(map->full) || !char_is_printable(map->obstacle)
		|| !char_is_printable(map->empty))
	{
		map->status = error;
		return (error);
	}
	return (ok);
}

t_status	get_map_lines(char *map_str, int n, t_map *map)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (map_str[i] >= '0' && map_str[i] <= '9')
			map->lines = map->lines * 10 + map_str[i] - '0';
		else
		{
			map->status = error;
			return (error);
		}
		i++;
	}
	if (map->lines == 0)
	{
		map->status = error;
		return (error);
	}
	return (ok);
}

int	get_end_of_line(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\n')
		count++;
	return (count);
}

t_status	char_is_printable(char c)
{
	if (c < 0 || (c >= ' ' && c < 127))
		return (ok);
	else
		return (error);
}

char	**read_maps(int argc, char **files, int *map_qty)
{
	char 	**maps;

	*map_qty = 0;
	maps = NULL;
	if (argc == 1)
	{
		files = read_stdin(map_qty);
		maps = read_files(*map_qty, files, map_qty);
	}
	else
		maps = read_files(argc - 1, (files + 1), map_qty);
	return(maps);
}

char	**read_files(int file_qty, char **files, int *map_qty)
{
	int		i;
	char 	**maps;

	maps = (char **)malloc(sizeof(char *) * (file_qty));
	if (!maps)
		exit(input);
	i = 0;
	*map_qty = 0;
	while (i < file_qty)
	{
		maps[i] = read_file_content(files[i], get_file_size(files[i]));
		i++;
		*map_qty += 1;
	}
	return (maps);
}

char	*read_file_content(char *path, int size)
{
	int		fd;
	char	*content;
	ssize_t	nr;

	content = (char *) malloc(sizeof(char) * (size + 1));
	if (!content)
		exit(input);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, path, 15);
		write(1, "File not found\n", 15);
		exit(input);
	}
	nr = read(fd, content, size + 1);
	close (fd);
	return (content);
}

int	get_file_size(char *path)
{
	int		numc;
	int		fd;
	char	c[1];

	numc = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "File not found\n", 15);
		exit(input);
	}
	while (read(fd, c, sizeof(char)))
		numc++;
	if (!numc)
	{
		write(1, "Empty file:", 11);
		exit(input);
	}
	close (fd);
	return (numc);
}

char	**ft_check_stdin(char **arguments, char **content, int len)
{
	int	fd;
	int	i;
	int	j;

	i = 0;
	j = 0;
	fd = 0;
	while (i < (len - 1))
	{
		fd = open (arguments[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstrerror("map error");
			close (fd);
		}
		else
		{
			content[j++] = read_file_content(arguments[i],
					get_file_size(arguments[i]));
			close (fd);
		}
		i++;
	}
	content[j] = NULL;
	return (content);
}

char	**read_stdin(int *len)
{
	char	buf[BUF_SIZE + 1];
	// char	buf[BUF_SIZE + 1] = "example_perl1 example_perl2 example_file";
	char	**files;

	*len = 0;
	read (STDIN_FILENO, buf, BUF_SIZE);
	files = ft_split(buf, " \n\0", len);
	return (files);
}

char	**ft_check_argv(char **argv, char **content, int argc)
{
	int	fd;
	int	i;
	int	j;

	i = 1;
	j = 0;
	fd = 0;
	while (i < argc)
	{
		fd = open (argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstrerror("map error");
			close(fd);
		}
		else
		{
			content[j] = read_file_content(argv[i], get_file_size(argv[i]));
			j++;
			close(fd);
		}
		i++;
	}
	content[j] = NULL;
	return (content);
}

char	**read_argv(int argc, char **argv)
{
	char	**content;

	content = (char **)malloc(sizeof (char *) * argc);
    if (content == NULL)
        return (NULL);
	content = ft_check_argv(argv, content, argc);
	return (content);
}

int	ft_charcmp(char str, char *charset)
{
	int	i;

	i = 0;
	while (*charset)
	{
		if (str == *charset)
			return (0);
		charset++;
	}
	return (1);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size, int *pos)
{
	unsigned int	i;
	unsigned int	c;

	c = 0;
	i = 0;
	while (src[c] != '\0')
		++c;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[*pos];
			++i;
			(*pos)++;
		}
		dest[i] = '\0';
	}
	return (c);
}

int	ft_strlen_charset(char *str, char *charset, int *i)
{
	int	c;
	int	j;

	j = 0;
	c = 0;
	while (str[*i] != '\0')
	{
		while (charset[j] != '\0')
		{
			if (ft_charcmp(str[*i], charset) == 0)
				return (c);
			j++;
		}
			c++;
			j = 0;
			(*i)++;
	}
	return (c);
}

int	ft_size(char *str, char *charset)
{
	int	chars;
	int	c;

	chars = 0;
	c = 0;
	while (*str != '\0')
	{
		if (ft_charcmp(*str, charset) == 0 && chars > 0)
		{
			c++;
			chars = 0;
		}
		if (ft_charcmp(*str, charset) == 1)
			chars++;
		str++;
	}
	if (chars > 0)
		c++;
	return (c);
}

char	**ft_split(char *str, char *charset, int *map_qty)
{
	int		pos;
	int		cpy;
	int		n;
	char	**split;
	int		len;

	n = 0;
	pos = 0;
	len = 0;
	cpy = 0;
	
	*map_qty = ft_size(str, charset);
	split = (char **) malloc(sizeof (char *) * (*map_qty + 1));
	while (n < ft_size(str, charset))
	{	
		while (ft_charcmp(str[pos], charset) == 0)
		{
			pos++;
			cpy++;
		}
		len = ft_strlen_charset(str, charset, &pos);
		split[n] = (char *) malloc(sizeof (char) * len + 1);
		ft_strlcpy(split[n], str, len + 1, &cpy);
		n++;
	}
	split[n] = NULL;
	return (split);
}
void ft_putstrerror (char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(2, &str[i], 1);
        i++;
    }
    write(2, "\n", 1);
}

void	ft_print_solution(t_map map)
{
	int		i;
	int		j;

	map.status = ok;
	i = 0;
	if (map.status == error)
		write(1, "Map error\n", 18);
	else if (map.status == ok)
	{
		while (i < map.lines)
		{
			j = 0;
			while (j < map.columns)
			{
				write(1, &map.box[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}
