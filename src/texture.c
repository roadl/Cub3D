/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:29:36 by yojin             #+#    #+#             */
/*   Updated: 2024/12/20 22:38:55 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	print_textures(t_texture *t)
{
	int	y;
	int	x;

	y = -1;
	while (++y < t->height)
	{
		x = -1;
		while (++x < t->width)
			printf("%#X ", t->texture[y][x]);
	}
}

static int	**allocate_2d_array(int rows, int cols)
{
	int	**array;
	int	i;

	array = (int **)malloc(sizeof(int *) * rows);
	if (!array)
		fail_exit();
	i = -1;
	while (++i < rows)
	{
		array[i] = (int *)malloc(sizeof(int) * cols);
		if (!array[i])
			fail_exit();
	}
	return (array);
}

static void	copy_color(t_texture *t, char *img_data, int line_length, int bpp)
{
	int	y;
	int	x;

	y = -1;
	while (++y < t->height)
	{
		x = -1;
		while (++x < t->width)
			t->texture[y][x] = \
				*(int *)(img_data + (y * line_length) + (x * (bpp / 8)));
	}
}

// XPM 파일 색상 정보를 2차원 배열로 변환
static void	convert_xpm_to_array(t_mlx *mlx, t_texture *t)
{
	int		bpp;
	int		line_length;
	int		endian;
	char	*img_data;
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx_ptr, t->path, &t->width, &t->height);
	if (!img)
		fail_exit();
	img_data = mlx_get_data_addr(img, &bpp, &line_length, &endian);
    t->texture = allocate_2d_array(t->height, t->width);
	copy_color(t, img_data, line_length, bpp);
	mlx_destroy_image(mlx->mlx_ptr, img);
}

void	init_textures(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < 4)
		convert_xpm_to_array(mlx, &mlx->info.textures[i]);
	print_textures(mlx->info.textures);
}