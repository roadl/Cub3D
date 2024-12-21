/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:03:56 by yojin             #+#    #+#             */
/*   Updated: 2024/12/21 17:11:18 by yojin            ###   ########.fr       */
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
	print_map(info);
	print_player(info->person);
	printf("width: %d, height: %d\n", info->map_width, info->map_height);
	printf("NO: %s\n", info->textures[NO].path);
	printf("SO: %s\n", info->textures[SO].path);
	printf("WE: %s\n", info->textures[WE].path);
	printf("EA: %s\n", info->textures[EA].path);
	printf("floor: %#X\n", info->floor_color);
	printf("celling: %#X\n", info->celling_color);
}

void	print_texture_window(t_mlx *mlx)
{
	for (int i = 0; i < 4; i++)
		for (int y = 0; y < mlx->info.textures[i].height * 2; y++)
			for (int x = 0; x < mlx->info.textures[i].width * 2; x++)
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x + i * mlx->info.textures[i].width * 2, y, mlx->info.textures[i].texture[y / 2][x / 2]);
}

void	leaks(void)
{
	system("leaks cub3D");
}
