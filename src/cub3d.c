#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Arguemnt count must be 2\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	cub3d_parse(&info, argv[1]);
	return (0);
}
