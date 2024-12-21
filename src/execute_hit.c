/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:11:55 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/21 20:12:10 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	cal_hit_pos(t_mlx *mlx)
{
	if (mlx->ray.dy > 0 && mlx->hit.hit_dir == -3) // 방향들 잘 체크하기
		mlx->hit.x_pos = 1 - mlx->hit.x_pos;
	if (mlx->ray.dx < 0 && mlx->hit.hit_dir == -2)
		mlx->hit.x_pos = 1 - mlx->hit.x_pos;

	printf("texture coordinate: %lf", mlx->hit.x_pos);
	if (mlx->hit.x_pos < 0)
		mlx->hit.x_pos = 0;
	else if (mlx->hit.x_pos > 1)
		mlx->hit.x_pos = 1;
}

void	cal_hit_dir(t_mlx *mlx)
{
	if (mlx->hit.hit_dir == -2)
	{
		if (mlx->ray.dx < 0)
			mlx->hit.hit_dir = 3;
		else
			mlx->hit.hit_dir = 2;
	}
	else
	{
		if (mlx->ray.dy < 0)
			mlx->hit.hit_dir = 1;
		else
			mlx->hit.hit_dir = 0;
	}
}

void	cal_hit_parameter(t_mlx *mlx)
{
	if (mlx->hit.hit_dir == -2)
	{
		mlx->hit.distance = mlx->ray.x_dist - mlx->ray.delta_x;
		mlx->hit.x_pos = mlx->info.person.y_pos + mlx->ray.dy * mlx->hit.distance - mlx->ray.y_pos;
	}
	if (mlx->hit.hit_dir == -3)
	{
		mlx->hit.distance = mlx->ray.y_dist - mlx->ray.delta_y;
		mlx->hit.x_pos = mlx->info.person.x_pos + mlx->ray.dx * mlx->hit.distance - mlx->ray.x_pos;
	}
	else
		error_occur(mlx, "hit error", 1);
	cal_hit_pos(mlx);
	cal_hit_dir(mlx);
}
