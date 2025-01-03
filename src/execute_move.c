/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:47:17 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/22 00:38:57 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ft_move_w(t_mlx *mlx)
{
	double	dx;
	double	dy;

	dx = mlx->info.person.x_dir * MOVE_SPEED;
	dy = mlx->info.person.y_dir * MOVE_SPEED;
	if (!check_vaild_pos(mlx, dx, dy))
		return ;
	if (mlx->info.map[(int)(mlx->info.person.y_pos)]
		[(int)(mlx->info.person.x_pos + dx * SAFE_DISTANCE)] == '0')
		mlx->info.person.x_pos += dx;
	if (mlx->info.map[(int)(mlx->info.person.y_pos + dy * SAFE_DISTANCE)]
	[(int)(mlx->info.person.x_pos)] == '0')
		mlx->info.person.y_pos += dy;
}

void	ft_move_d(t_mlx *mlx)
{
	double	dx;
	double	dy;

	dx = mlx->info.person.x_dir * MOVE_SPEED;
	dy = mlx->info.person.y_dir * MOVE_SPEED;
	rotate_vector(&dx, &dy, PI / 2);
	if (!check_vaild_pos(mlx, dx, dy))
		return ;
	if (mlx->info.map[(int)(mlx->info.person.y_pos)]
	[(int)(mlx->info.person.x_pos + dx * SAFE_DISTANCE)] == '0')
		mlx->info.person.x_pos += dx;
	if (mlx->info.map[(int)(mlx->info.person.y_pos + dy * SAFE_DISTANCE)]
	[(int)(mlx->info.person.x_pos)] == '0')
		mlx->info.person.y_pos += dy;
}

void	ft_move_s(t_mlx *mlx)
{
	double	dx;
	double	dy;

	dx = mlx->info.person.x_dir * MOVE_SPEED;
	dy = mlx->info.person.y_dir * MOVE_SPEED;
	rotate_vector(&dx, &dy, PI);
	if (!check_vaild_pos(mlx, dx, dy))
		return ;
	if (mlx->info.map[(int)(mlx->info.person.y_pos)]
	[(int)(mlx->info.person.x_pos + dx * SAFE_DISTANCE)] == '0')
		mlx->info.person.x_pos += dx;
	if (mlx->info.map[(int)(mlx->info.person.y_pos + dy * SAFE_DISTANCE)]
	[(int)(mlx->info.person.x_pos)] == '0')
		mlx->info.person.y_pos += dy;
}

void	ft_move_a(t_mlx *mlx)
{
	double	dx;
	double	dy;

	dx = mlx->info.person.x_dir * MOVE_SPEED;
	dy = mlx->info.person.y_dir * MOVE_SPEED;
	rotate_vector(&dx, &dy, -1 * PI / 2);
	if (!check_vaild_pos(mlx, dx, dy))
		return ;
	if (mlx->info.map[(int)(mlx->info.person.y_pos)]
	[(int)(mlx->info.person.x_pos + dx * SAFE_DISTANCE)] == '0')
		mlx->info.person.x_pos += dx;
	if (mlx->info.map[(int)(mlx->info.person.y_pos + dy * SAFE_DISTANCE)]
	[(int)(mlx->info.person.x_pos)] == '0')
		mlx->info.person.y_pos += dy;
}

void	ft_turn(t_mlx *mlx, char ch)
{
	double	temp;
	double	angle;

	if (ch == 'R')
		angle = (double)TURN_SPEED;
	else
		angle = (double)(-1 * TURN_SPEED);
	temp = mlx->info.person.x_dir * cos(angle)
		- mlx->info.person.y_dir * sin(angle);
	mlx->info.person.y_dir = mlx->info.person.x_dir
		* sin(angle) + mlx->info.person.y_dir * cos(angle);
	mlx->info.person.x_dir = temp;
	temp = mlx->info.person.x_camera * cos(angle)
		- mlx->info.person.y_camera * sin(angle);
	mlx->info.person.y_camera = mlx->info.person.x_camera
		* sin(angle) + mlx->info.person.y_camera * cos(angle);
	mlx->info.person.x_camera = temp;
}
