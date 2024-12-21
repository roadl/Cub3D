/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:05:07 by yojin             #+#    #+#             */
/*   Updated: 2024/12/22 00:27:08 by yuyu             ###   ########.fr       */
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

	wall_height = (double)WIN_Y /mlx->hit.distance;
	*y_ratio = -(WIN_Y - wall_height) / 2 / wall_height;
	*delta_y = 1 / wall_height;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char			*dst;
	unsigned int	*temp;

	if (x < 0 || y < 0 || x >= WIN_X || y >= WIN_Y)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	temp = (unsigned int *)dst;
	*temp = color;
}
