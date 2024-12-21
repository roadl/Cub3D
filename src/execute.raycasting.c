/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:21:59 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/21 19:51:00 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	cal_sidedist(t_mlx *mlx) // 이거 소수점 오차도 나중에 생각해서 고쳐야함. map으로 해결한듯.
{
	if (mlx->ray.dx < 0)
	{
		mlx->ray.x_step = -1;
		mlx->ray.x_dist += (mlx->info.person.x_pos - mlx->ray.x_pos)
			* mlx->ray.delta_x;
	}
	else
	{
		mlx->ray.x_step = 1;
		mlx->ray.x_dist += (mlx->ray.x_pos + 1 - mlx->info.person.x_pos)
			* mlx->ray.delta_x;
	}
	if (mlx->ray.dy < 0)
	{
		mlx->ray.y_step = -1;
		mlx->ray.y_dist += (mlx->info.person.y_pos - mlx->ray.y_pos)
			* mlx->ray.delta_y;
	}
	else
	{
		mlx->ray.y_step = 1;
		mlx->ray.y_dist += (mlx->ray.y_pos + 1 - mlx->info.person.y_pos)
			* mlx->ray.delta_y;
	}
}

void	ray_setting(t_mlx *mlx, int x) // 미완
{
	double	temp;
	double	angle;
	// 현재 위치
	mlx->ray.x_pos = (int)(mlx->info.person.x_pos);
	mlx->ray.y_pos = (int)(mlx->info.person.y_pos);
	angle = FOV - x * DIV_ANGLE; // 메이비 왼쪽부터?
	mlx->ray.dx = mlx->info.person.x_dir * cos(angle) - mlx->info.person.y_dir * sin(angle);
	mlx->ray.dy = mlx->info.person.x_dir
		* sin(angle) + mlx->info.person.y_dir * cos(angle);
	if (fabs(mlx->ray.dx) < ALMOSTZERO)
		mlx->ray.delta_x = 1 / ALMOSTZERO;
	else
		mlx->ray.delta_x = fabs(1 / mlx->ray.dx);
	if (fabs(mlx->ray.dy) < ALMOSTZERO)
		mlx->ray.delta_y = 1 / ALMOSTZERO;
	else
		mlx->ray.delta_y = fabs(1 / mlx->ray.dy);
	cal_sidedist(mlx);
}

void	dda_algorithm(t_mlx *mlx)
{
	bool	hit;

	hit = false;
	mlx->hit.hit_dir = -1;
	while (!hit)
	{
		if (mlx->ray.x_dist < mlx->ray.y_dist)
		{
			mlx->ray.x_dist += mlx->ray.delta_x;
			mlx->ray.x_pos += mlx->ray.x_step;
			mlx->hit.hit_dir = -2;
		}
		else
		{
			mlx->ray.y_dist += mlx->ray.delta_y;
			mlx->ray.y_pos += mlx->ray.y_step;
			mlx->hit.hit_dir = -3;
		}
		if (mlx->info.map[mlx->ray.y_pos][mlx->ray.x_pos] == '1')
			hit = true;
	}
}

void	cal_hit_pos(t_mlx *mlx)
{
	if (mlx->ray.dy > 0 && mlx->hit.hit_dir == -3)
		mlx->hit.x_pos = 1 - mlx->hit.x_pos;
	if (mlx->ray.dx > 0 && mlx->hit.hit_dir == -2)
		mlx->hit.x_pos = 1 - mlx->hit.x_pos;

	printf("texture coordinate: %lf", mlx->hit.x_pos);
	if (mlx->hit.x_pos < 0)
		mlx->hit.x_pos = 0;
	else if (mlx->hit.x_pos > 1)
		mlx->hit.x_pos = 1;
}

void	cal_hit_dir(t_mlx *mlx)
{

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

void	ray_casting(t_mlx *mlx)
{
	int x;

	x = -1;
	while (++x < WIN_X)
	{
		ray_setting(mlx, x);
		dda_algorithm(mlx);
		cal_hit_parameter(mlx);
		texture_mapping(mlx, x); // 미완
	}
}

void	render_sceen(t_mlx *mlx) // 미완
{
	ray_casting(mlx);
	draw_sceen(mlx);
}
