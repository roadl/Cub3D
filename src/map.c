/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:09:54 by yojin             #+#    #+#             */
/*   Updated: 2024/12/21 20:07:35 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
		line = free_and_gnl(line, fd);
	}
	info->map[info->map_height] = NULL;
	free(line);
	close(fd);
}

void	init_player(t_info *info, int x, int y)
{
	t_person	*p;

	p = &info->person;
	if (p->x_pos >= 0)
		error_exit("Duplicate Player Position!!\n");
	p->x_pos = x + 0.5;
	p->y_pos = y + 0.5;
	if (info->map[y][x] == 'N')
		p->y_dir = -1;
	if (info->map[y][x] == 'S')
		p->y_dir = 1;
	if (info->map[y][x] == 'E')
		p->x_dir = 1;
	if (info->map[y][x] == 'W')
		p->x_dir = -1;
	info->map[y][x] = '0';
}

void	check_map_valid(t_info *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < info->map_height)
	{
		x = -1;
		while (++x < info->map_width)
		{
			if (ft_isalpha(info->map[y][x]))
				init_player(info, x, y);
			if (!is_valid_point(info, x, y))
				error_exit("Invalid Map!!\n");
		}	
	}
	if (info->person.x_pos < 0)
		error_exit("No Player in map!!\n");
}

void	parse_map(t_info *info, char *path)
{
	int	y;
	int	x;

	get_map_info(info, path);
	init_map(info, path);
	check_map_valid(info);
	y = -1;
	while (++y < info->map_height)
	{
		x = -1;
		while (++x < info->map_width)
			if (info->map[y][x] == ' ')
				info->map[y][x] = '1';
	}
}
