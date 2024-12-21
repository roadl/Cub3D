/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:03:50 by yojin             #+#    #+#             */
/*   Updated: 2024/12/22 01:46:40 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// 파일 열리는지 확인, .cub으로 끝나는지 확인
void	check_cub_file(char *path)
{
	char	len;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("cub3d");
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
		error_exit("Cannot using Directory\n");
	len = ft_strlen(path);
	if (ft_strncmp(path + len - 4, ".cub", 4) != 0)
		error_exit("The file must be a .cub extension\n");
}

void	check_xpm_file(char *path)
{
	char	len;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("cub3d");
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
		error_exit("Cannot using Directory\n");
	len = ft_strlen(path);
	if (ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		error_exit("The image must be a .xpm extension\n");
}

static int	check_color(char *str)
{
	int		i;
	int		n;
	char	*trim;

	trim = ft_strtrim(str, " \t\n");
	if (!trim)
		fail_exit();
	i = 0;
	if (!trim[0] || trim[i] == '\n')
		return (0);
	while (trim[i])
		if (!ft_isdigit(trim[i++]))
			return (0);
	n = int_atoi(trim);
	free(trim);
	if (n < 0 || n > 255)
		return (0);
	return (1);
}

void	check_color_valid(char **strs)
{
	int	i;

	i = 0;
	while (i < 3)
		if (!check_color(strs[i++]))
			error_exit("Color Value Error!!\n");
}

void	check_info_valid(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
		if (!info->textures[i++].path)
			error_exit("Texture Info Missing!!\n");
	if (info->celling_color == -1 || info->floor_color == -1)
		error_exit("Color Info Missing!!\n");
}
