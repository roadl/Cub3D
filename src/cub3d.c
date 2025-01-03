/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:09:47 by yojin             #+#    #+#             */
/*   Updated: 2024/12/22 00:53:21 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"
#include "execute.h"

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
	init_textures(mlx);
	mlx->info.person.x_camera = mlx->info.person.x_dir;
	mlx->info.person.y_camera = mlx->info.person.y_dir;
	rotate_vector(&mlx->info.person.x_camera,
		&mlx->info.person.y_camera, -1 * PI / 2);
	mlx->info.person.fov = PI / 3;
	mlx->info.person.x_camera *= tan(mlx->info.person.fov / 2);
	mlx->info.person.y_camera *= tan(mlx->info.person.fov / 2);
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
}

int	loop_main(t_mlx *mlx)
{
	if (!mlx->key_state)
		return (0);
	person_move(mlx);
	render_sceen(mlx);
	return (0);
}

void	cub3d(t_mlx *mlx)
{
	mlx_start(mlx);
	render_sceen(mlx);
	mlx_hook(mlx->win_ptr, X_EVNET_EXIT, 0, &program_end, mlx);
	mlx_hook(mlx->win_ptr, X_EVNET_KEY_PRESS, 0, &key_press, mlx);
	mlx_hook(mlx->win_ptr, X_EVNET_KEY_RELEASE, 0, &key_release, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &loop_main, mlx);
	mlx_loop(mlx->mlx_ptr);
	program_end(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Arguemnt count must be 2\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	cub3d_parse(&mlx.info, argv[1]);
	cub3d(&mlx);
	program_end(&mlx);
	return (0);
}
