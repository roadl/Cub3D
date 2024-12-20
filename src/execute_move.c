/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:47:17 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/20 20:39:59 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ft_move_w(t_mlx *mlx)
{
	double	dy;

	dy = -1 * MOVE_SPEED;
	if (mlx->person.y_pos + dy - SAFE_DISTANCE > 0 &&
		mlx->info.map[(int)(mlx->person.y_pos + dy)][(int)mlx->person.x_pos] == '0')
		mlx->person.y_pos += dy;
}

void	ft_move_a(t_mlx *mlx)
{
	double	dx;

	dx = -1 * MOVE_SPEED;
	if (mlx->person.x_pos + dx - SAFE_DISTANCE > 0 &&
		mlx->info.map[(int)mlx->person.y_pos][(int)(mlx->person.x_pos + dx)] == '0')
		mlx->person.x_pos += dx;
}

void	ft_move_s(t_mlx *mlx)
{
	double	dy;

	dy = MOVE_SPEED;
	if (mlx->person.y_pos + dy + SAFE_DISTANCE < mlx->info.map_height &&
		mlx->info.map[(int)(mlx->person.y_pos + dy)][(int)mlx->person.x_pos] == '0')
		mlx->person.y_pos += dy;
}

void	ft_move_d(t_mlx *mlx)
{
	double	dx;

	dx = MOVE_SPEED;
	if (mlx->person.x_pos + dx + SAFE_DISTANCE < mlx->info.map_width &&
		mlx->info.map[(int)mlx->person.y_pos][(int)(mlx->person.x_pos + dx)] == '0')
		mlx->person.x_pos += dx;
}

void	ft_turn(t_mlx *mlx, char ch)
{
	double	x_angle;
	double	turn_angle;

	if (ch == 'l') // 방향 체크해보기
		turn_angle = (double)TURN_SPEED;
	else
		turn_angle = (double)(-1 * TURN_SPEED);

	x_angle = mlx->person.x_dir * cos(turn_angle) - mlx->person.y_dir * sin(turn_angle);
	mlx->person.y_dir = mlx->person.x_dir * sin(turn_angle) + mlx->person.y_dir * cos(turn_angle);
	mlx->person.x_dir = x_angle;
}
