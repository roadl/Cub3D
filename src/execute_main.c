/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:07:45 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/21 21:08:04 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

// void	test_print(t_mlx *mlx)
// {
// 	mlx->test++;
// 	printf("%d: %d = x_pos: %lf    y_pos: %lf      x_angle: %lf    y_angle: %lf\n", mlx->test, mlx->key_state, mlx->info.person.x_pos, mlx->info.person.y_pos, mlx->info.person.x_dir, mlx->info.person.y_dir);
// }

void	mlx_start(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, "cub3d");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y);
	if (!mlx->win_ptr || !mlx->img.img_ptr)
		error_occur(mlx, "mlx ptr error", 1);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	if (!mlx->img.addr)
		error_occur(mlx, "mlx_get_data_addr error", 1);
}

void	person_move(t_mlx *mlx)
{
	if (mlx->key_state & W_STATE && !(mlx->key_state & S_STATE))
		ft_move_w(mlx);
	if (mlx->key_state & A_STATE && !(mlx->key_state & D_STATE))
		ft_move_a(mlx);
	if (mlx->key_state & S_STATE && !(mlx->key_state & W_STATE))
		ft_move_s(mlx);
	if (mlx->key_state & D_STATE && !(mlx->key_state & A_STATE))
		ft_move_d(mlx);
	if (mlx->key_state & LEFT_STATE && !(mlx->key_state & RIGHT_STATE))
		ft_turn(mlx, 'L');
	if (mlx->key_state & RIGHT_STATE && !(mlx->key_state & LEFT_STATE))
		ft_turn(mlx, 'R');
	// 나중에 지우기
	// test_print(mlx);
}

int	loop_main(t_mlx *mlx)
{
	if (!mlx->key_state)
		return (0);
	person_move(mlx);
	render_sceen(mlx);
	return (0);
}

int	execute_main(t_mlx *mlx)
{
	mlx_start(mlx);
	render_sceen(mlx);
	mlx_hook(mlx->win_ptr, X_EVNET_EXIT, 0, &program_end, mlx);
	mlx_hook(mlx->win_ptr, X_EVNET_KEY_PRESS, 0, &key_press, mlx);
	mlx_hook(mlx->win_ptr, X_EVNET_KEY_RELEASE, 0, &key_release, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &loop_main, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

// int	main(void)
// {
// 	t_mlx	mlx;

// 	ft_memset(&mlx, 0, sizeof(mlx));
// 	mlx.info.person.x_pos = 1.5;
// 	mlx.info.person.y_pos = 1.5;
// 	mlx.info.person.x_dir = 1;
// 	mlx.info.map_height = 40;
// 	mlx.info.map_width = 40;
// 	for (int i = 0; i < mlx.info.map_height; i++)
// 	{
// 		for (int j = 0; j < mlx.info.map_width; j++)
// 			mlx.info.map[i][j] = '0';
// 	}
// 	execute_main(&mlx);
// 	return (0);
// }
