/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:09:47 by yojin             #+#    #+#             */
/*   Updated: 2024/12/21 19:50:47 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"

#define WIN_WIDTH	1080
#define WIN_HEIGHT	720
#define	SEG			1

void	foo(t_mlx *mlx)
{
	for (int i = 0; i < SEG; i++)
		for (int x = i * WIN_WIDTH / SEG; x < (i + 1) * WIN_WIDTH / SEG; x++)
			print_texture_line(mlx, (double)x / WIN_WIDTH, x, i % 4, x);
}

void	cub3d(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	init_textures(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, \
		&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	print_texture_window(mlx);
	foo(mlx);
	mlx_loop(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		i;

	//atexit(leaks);
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Arguemnt count must be 2\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	cub3d_parse(&mlx.info, argv[1]);
	cub3d(&mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
