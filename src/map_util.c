/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:06:39 by yojin             #+#    #+#             */
/*   Updated: 2024/12/22 02:01:23 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_valid_point(t_info *info, int x, int y, int *flag)
{
	if (y == 0)
		*flag = 1;
	else if (info->map[y][x] != ' ' && info->map[y - 1][x] != ' ')
		*flag = 1;
	if (info->map[y][x] != '0')
		return (1);
	if (x <= 0 || y <= 0 || \
		x >= (info->map_width - 1) || y >= (info->map_height - 1))
		return (0);
	if (info->map[y - 1][x] == ' ' || info->map[y + 1][x] == ' ' || \
		info->map[y][x - 1] == ' ' || info->map[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	is_map_char(char c)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
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

int	cal_width(char *line)
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

void	copy_line(char *map_row, char *line, int width)
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
