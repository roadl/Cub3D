#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		error_exit("argc must be 2\n");
	cub3d_parse(&info, argv[1]);
	return (0);
}
