#include "cub3d.h"
#include "../gnl/get_next_line.h"

static void	process_line(t_info *info, char *line)
{
	printf("line: %s", line);
}

static void	read_file(t_info *info, char *path)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("cub3d");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		process_line(info, line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	check_info_valid(t_info *info)
{

}

static void	check_map_valid(t_info *info)
{

}

void	cub3d_parse(t_info *info, char *path)
{
	check_file(path);
	read_file(info, path);
	check_info_valid(info);
	check_map_valid(info);
}
