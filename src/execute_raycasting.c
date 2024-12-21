/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:21:59 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/21 22:16:19 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "parse.h"

static void	cal_sidedist(t_mlx *mlx) // 이거 소수점 오차도 나중에 생각해서 고쳐야함. map으로 해결한듯.
{
	if (mlx->ray.dx < 0)
	{
		mlx->ray.x_step = -1;
		mlx->ray.x_dist = (mlx->info.person.x_pos - mlx->ray.x_pos)
			* mlx->ray.delta_x;
	}
	else
	{
		mlx->ray.x_step = 1;
		mlx->ray.x_dist = (mlx->ray.x_pos + 1 - mlx->info.person.x_pos)
			* mlx->ray.delta_x;
	}
	if (mlx->ray.dy < 0)
	{
		mlx->ray.y_step = -1;
		mlx->ray.y_dist = (mlx->info.person.y_pos - mlx->ray.y_pos)
			* mlx->ray.delta_y;
	}
	else
	{
		mlx->ray.y_step = 1;
		mlx->ray.y_dist = (mlx->ray.y_pos + 1 - mlx->info.person.y_pos)
			* mlx->ray.delta_y;
	}
}

static void	ray_setting(t_mlx *mlx, int x)
{
	double	angle;
	// 현재 위치
	mlx->ray.x_pos = (int)(mlx->info.person.x_pos);
	mlx->ray.y_pos = (int)(mlx->info.person.y_pos);
	angle = FOV - x * DIV_ANGLE; // 메이비 왼쪽부터?
	mlx->ray.dx = mlx->info.person.x_dir
		* cos(angle) - mlx->info.person.y_dir * sin(angle);
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

static void	dda_algorithm(t_mlx *mlx)
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

void	ray_casting(t_mlx *mlx)
{
	int	x;

	x = -1;
	while (++x < WIN_X)
	{
		ray_setting(mlx, x);
		// printf("person_x: %lf, person_y: %lf, dx: %lf, dy: %lf, delta_x: %lf, delta_y: %lf, x_dist: %lf, y_dist : %lf, x_pos: %d, y_pos: %d, x_step:%d, y_step:%d\n", mlx->info.person.x_pos, mlx->info.person.y_pos, mlx->ray.dx, mlx->ray.dy, mlx->ray.delta_x, mlx->ray.delta_y, mlx->ray.x_dist, mlx->ray.y_dist, mlx->ray.x_pos, mlx->ray.y_pos, mlx->ray.x_step, mlx->ray.y_step);
		dda_algorithm(mlx);
		cal_hit_parameter(mlx);
		texture_mapping(mlx, x);
	}
}

void	render_sceen(t_mlx *mlx)
{
	ray_casting(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
}
