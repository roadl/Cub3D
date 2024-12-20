#include "parse.h"

static int	is_map_char(char c)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (1);
	return (0);
}

int	is_line_map(char *line)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (line[++i])
	{
		if (ft_isspace(line[i]))
			continue ;
		if (!is_map_char(line[i]))
			return (0);
		flag = 1;
	}
	if (flag)
		return (1);
	return (0);
}

static int	cal_width(char *line)
{
	int	width;
	int	i;

	i = 0;
	width = 0;
	while (line[i])
	{
		if (is_map_char(line[i]))
			width = i + 1;
		i++;
	}
	return (width);
}

static void	copy_line(char *map_row, char *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i < ft_strlen(line) && !ft_isspace(line[i]))
			map_row[i] = line[i];
		else
			map_row[i] = ' ';
		i++;
	}
	map_row[width] = '\0';
}

void	get_map_info(t_info *info, char *path)
{
	char	*line;
	int		fd;
	int		width;

	fd = open_with_check(path, O_RDONLY);
	line = get_next_line(fd);
	while (line && !is_line_map(line))
		line = free_and_gnl(line, fd);
	while (line && !is_empty(line))
	{
		if (!is_line_map(line))
			error_exit("Invalid Map!!\n");
		info->map_height++;
		width = cal_width(line);
		if (info->map_width < width)
			info->map_width = width;
		line = free_and_gnl(line, fd);
	}
	line = free_and_gnl(line, fd);
	while (line && is_empty(line))
		line = free_and_gnl(line, fd);
	if (line)
		error_exit("Info After Map!!\n");
	free(line);
	close(fd);
}

void	init_map(t_info *info, char *path)
{
	char	*line;
	int		fd;
	int		i;

	fd = open_with_check(path, O_RDONLY);
	line = get_next_line(fd);
	while (line && !is_line_map(line))
		line = free_and_gnl(line, fd);
	i = 0;
	info->map = (char **)malloc(sizeof(char *) * (info->map_height + 1));
	while (line && i < info->map_height)
	{
		info->map[i] = \
			(char *)malloc(sizeof(char) * (info->map_width + 1));
		copy_line(info->map[i++], line, info->map_width);
		printf("copied line: %s\n", info->map[i - 1]);
		line = free_and_gnl(line, fd);
	}
	info->map[info->map_height] = NULL;
	free(line);
	close(fd);
}

void	check_map_valid(t_info *info)
{
	int	y;
	int	x;
	int	count;

	y = -1;
	count = 0;
	while (++y < info->map_height)
	{
		x = -1;
		while (++x < info->map_width)
		{
			if (ft_isalpha(info->map[y][x]) && count != 0)
				error_exit("Duplicate Player Postion!!\n");
		}
	}
}

void	parse_map(t_info *info, char *path)
{
	get_map_info(info, path);
	init_map(info, path);
	printf("width: %d, height: %d\n", info->map_width, info->map_height);
	print_map(info);
	check_map_valid(info);
}
