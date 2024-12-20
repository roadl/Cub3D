#include "parse.h"

void	print_map(t_info *info)
{
	int		i;
	char	**map;

	i = 0;
	map = info->map;
	printf("========= map =========\n");
	while (map[i])
		printf("%s\n", map[i++]);
	printf("=======================\n");
}

void	print_info(t_info *info)
{
	t_color	floor;
	t_color	celling;

	floor = info->floor_color;
	celling = info->celling_color;
	printf("NO: %s\n", info->textures[NO].path);
	printf("SO: %s\n", info->textures[SO].path);
	printf("WE: %s\n", info->textures[WE].path);
	printf("EA: %s\n", info->textures[EA].path);
	printf("floor: %d, %d, %d\n", floor.r, floor.g, floor.b);
	printf("celling: %d, %d, %d\n", celling.r, celling.g, celling.b);
}