#include "parse.h"

// 파일 열리는지 확인, .cub으로 끝나는지 확인
void	check_file(char *path)
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

static int	check_color(char *str)
{
	int	i;
	int	n;

	i = 0;
	if (!str[0] || str[i] == '\n')
		return (0);
	while (str[i] && str[i] != '\n')
		if (!ft_isdigit(str[i++]))
			return (0);
	n = ft_atoi(str);
	if (n < 0 || n > 255)
		return (0);
	return (1);
}

void	check_path_valid(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		fail_exit();
	close(fd);
	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
		error_exit("Cannot open Directory!!\n");
	close(fd);
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
	if (info->celling_color.r == -1 || info->floor_color.r == -1)
		error_exit("Color Info Missing!!\n");
}
