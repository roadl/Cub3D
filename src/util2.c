/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:05:07 by yojin             #+#    #+#             */
/*   Updated: 2024/12/22 01:46:06 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "execute.h"

static unsigned long	ft_strtol(char *str, int sign)
{
	unsigned long	i;
	unsigned long	ans;
	unsigned long	before;

	i = 0;
	ans = 0;
	before = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		ans = ans * 10 + str[i] - '0';
		if (before > ans && sign == 1)
			error_exit("Invalid Color Value!!\n");
		else if (ans >= 2147483648 && sign == 1)
			error_exit("Invalid Color Value!!\n");
		before = ans;
		i++;
	}
	return (sign * ans);
}

int	int_atoi(const char *str)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return ((int)ft_strtol((char *)(str + i), sign));
}

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

	wall_height = (double)WIN_Y / mlx->hit.distance;
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
