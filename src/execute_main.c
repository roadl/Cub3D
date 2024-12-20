/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:07:45 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/20 17:42:06 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	mlx_start(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, "cub3d");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y);
	if (!mlx->win_ptr || !mlx->img.img_ptr)
		error_occur(mlx, "mlx ptr error", 1);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	if (!mlx->img.addr)
		error_occur(mlx, "mlx_get_data_addr error", 1);
	mlx->person.speed = 0.1; // speed 지정
	// 나머지 초기화 작업.
}

void	person_move(t_mlx *mlx)
{
	//
}

int	loop_main(t_mlx *mlx)
{
	if (!mlx->key_state)
		return (0);
	person_move(mlx);
}

int	execute_main(t_mlx *mlx)
{
	mlx_start(mlx);
	mlx_hook(mlx->win_ptr, X_EVNET_EXIT, 0, &program_end, mlx);
	mlx_hook(mlx->win_ptr, X_EVNET_KEY_PRESS, 0, &key_press, mlx);
	mlx_hook(mlx->win_ptr, X_EVNET_KEY_RELEASE, 0, &key_release, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &loop_main, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	execute_main(&mlx);
	return (0);
}
