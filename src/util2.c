/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:05:07 by yojin             #+#    #+#             */
/*   Updated: 2024/12/21 21:27:21 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

void	init_info(t_info *info)
{
	int	i;

	i = 0;
	info->floor_color = -1;
	info->celling_color = -1;
	while (i < 4)
		info->textures[i++].path = NULL;
	info->map_width = 0;
	info->map_height = 0;
	info->person.x_dir = 0;
	info->person.y_dir = 0;
	info->person.x_pos = -1;
	info->person.y_pos = -1;
}

void	cal_texture_info(t_mlx *mlx, double *y_ratio, double *delta_y)
{
	double	wall_height;

	wall_height = (double)WIN_Y * 5 / (mlx->hit.distance + 1);
	*y_ratio = -(WIN_Y - wall_height) / 2 / wall_height;
	*delta_y = 1 / wall_height;
}
