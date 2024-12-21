/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:35:18 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/22 00:48:07 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	rotate_vector(double *dx, double *dy, double angle)
{
	double	temp;

	temp = *dx * cos(angle) - *dy * sin(angle);
	*dy = *dx * sin(angle) + *dy * cos(angle);
	*dx = temp;
}

int	check_vaild_pos(t_mlx *mlx, double dx, double dy)
{
	if (mlx->info.person.x_pos + dx * SAFE_DISTANCE > 0
		&& mlx->info.person.x_pos + dx * SAFE_DISTANCE < mlx->info.map_width
		&& mlx->info.person.y_pos + dy * SAFE_DISTANCE > 0
		&& mlx->info.person.y_pos + dy * SAFE_DISTANCE < mlx->info.map_height)
		return (1);
	return (0);
}
