#include "parse.h"
#include "../gnl/get_next_line.h"

static void	get_path_info(char *line, char **target)
{
	char	*str;

	if (*target)
		error_exit("Duplicate Texture Info!!\n");
	while (*line == ' ' || *line == '\t')
		line++;
	str = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!str)
		fail_exit();
	check_path_valid(str);
	*target = str;
}

static t_color	get_color_info(char *line, t_color *target_color)
{
	char	**strs;
	int		i;
	t_color	color;

	if (target_color->r != -1)
		error_exit("Duplicate Color Info!!\n");
	while (*line == ' ' || *line == '\t')
		line++;
	strs = ft_split(line, ',');
	if (!strs)
		fail_exit();
	if (!strs[0] || !strs[1] || !strs[2] || strs[3])
		error_exit("Color Format Error!!\n");
	check_color_valid(strs);
	color.r = ft_atoi(strs[0]);
	color.g = ft_atoi(strs[1]);
	color.b = ft_atoi(strs[2]);
	i = 0;
	while (i < 4)
		free(strs[i++]);
	free(strs);
	*target_color = color;
}

static void	process_line(t_info *info, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		get_path_info(line + 3, &info->textures[NO].path);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		get_path_info(line + 3, &info->textures[SO].path);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		get_path_info(line + 3, &info->textures[EA].path);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		get_path_info(line + 3, &info->textures[WE].path);
	else if (ft_strncmp(line, "F ", 2) == 0)
		get_color_info(line + 2, &info->floor_color);
	else if (ft_strncmp(line, "C ", 2) == 0)
		get_color_info(line + 2, &info->celling_color);
	else
		error_exit("Unexpected line!!\n");
}

static void	parse_file(t_info *info, char *path)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		fail_exit();
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		if (is_line_map(line))
		{
			parse_map(info, path);
			break ;
		}
		if (!is_empty(line))
			process_line(info, line);
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	close(fd);
}

void	init_info(t_info *info)
{
	int	i;

	i = 0;
	info->floor_color.r = -1;
	info->celling_color.r = -1;
	while (i < 4)
		info->textures[i++].path = NULL;
	info->map_width = 0;
	info->map_height = 0;
}

void	cub3d_parse(t_info *info, char *path)
{
	init_info(info);
	check_path_valid(path);
	parse_file(info, path);
	print_info(info);
	check_info_valid(info);
	check_map_valid(info);
}
