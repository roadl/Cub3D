/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:04:33 by yojin             #+#    #+#             */
/*   Updated: 2024/12/20 22:36:54 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	get_color_info(char *line, int *target_color)
{
	char	**strs;
	int		i;
	int		color;

	if (*target_color != -1)
		error_exit("Duplicate Color Info!!\n");
	while (*line == ' ' || *line == '\t')
		line++;
	strs = ft_split(line, ',');
	if (!strs)
		fail_exit();
	if (!strs[0] || !strs[1] || !strs[2] || strs[3])
		error_exit("Color Format Error!!\n");
	check_color_valid(strs);
	color = ft_atoi(strs[0]);
	color = color << 8;
	color += ft_atoi(strs[1]);
	color = color << 8;
	color += ft_atoi(strs[2]);
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

void	cub3d_parse(t_info *info, char *path)
{
	init_info(info);
	check_file(path);
	parse_file(info, path);
	print_info(info);
	check_info_valid(info);
	check_map_valid(info);
}
