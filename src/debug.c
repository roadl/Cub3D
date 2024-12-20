/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:03:56 by yojin             #+#    #+#             */
/*   Updated: 2024/12/20 21:12:25 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_player(t_person p)
{
	printf("Player pos: (%f, %f), dir: (%f, %f)\n", \
		p.x_pos, p.y_pos, p.x_dir, p.y_dir);
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

void	leaks(void)
{
	system("leaks cub3D");
}
