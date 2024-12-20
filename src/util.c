#include "cub3d.h"

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

void	error_exit(char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
