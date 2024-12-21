/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:47:17 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/21 20:39:56 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	ft_move_w(t_mlx *mlx)
{
	double	dy;

	dy = -1 * MOVE_SPEED;
	if (mlx->info.person.y_pos + dy - SAFE_DISTANCE > 0
		&& mlx->info.map[(int)(mlx->info.person.y_pos + dy)]
		[(int)mlx->info.person.x_pos] == '0')
		mlx->info.person.y_pos += dy;
}

void	ft_move_a(t_mlx *mlx)
{
	double	dx;

	dx = -1 * MOVE_SPEED;
	if (mlx->info.person.x_pos + dx - SAFE_DISTANCE > 0
		&& mlx->info.map[(int)mlx->info.person.y_pos]
		[(int)(mlx->info.person.x_pos + dx)] == '0')
		mlx->info.person.x_pos += dx;
}

void	ft_move_s(t_mlx *mlx)
{
	double	dy;

	dy = MOVE_SPEED;
	if (mlx->info.person.y_pos + dy + SAFE_DISTANCE < mlx->info.map_height
		&& mlx->info.map[(int)(mlx->info.person.y_pos + dy)]
		[(int)mlx->info.person.x_pos] == '0')
		mlx->info.person.y_pos += dy;
}

void	ft_move_d(t_mlx *mlx)
{
	double	dx;

	dx = MOVE_SPEED;
	if (mlx->info.person.x_pos + dx + SAFE_DISTANCE < mlx->info.map_width
		&& mlx->info.map[(int)mlx->info.person.y_pos]
		[(int)(mlx->info.person.x_pos + dx)] == '0')
		mlx->info.person.x_pos += dx;
}

void	ft_turn(t_mlx *mlx, char ch)
{
	double	temp;
	double	angle;

	if (ch == 'L') // 방향 체크해보기
		angle = (double)TURN_SPEED;
	else
		angle = (double)(-1 * TURN_SPEED);
	temp = mlx->info.person.x_dir * cos(angle)
		- mlx->info.person.y_dir * sin(angle);
	mlx->info.person.y_dir = mlx->info.person.x_dir
		* sin(angle) + mlx->info.person.y_dir * cos(angle);
	mlx->info.person.x_dir = temp;
}
