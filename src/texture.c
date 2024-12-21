/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:29:36 by yojin             #+#    #+#             */
/*   Updated: 2024/12/21 22:16:32 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	texture_mapping(t_mlx *mlx, int window_x)
{
	t_texture	t;
	double		delta_y;
	double		y_ratio;
	int			y;
	int			color;

	y = -1;
	t = mlx->info.textures[mlx->hit.hit_dir];
	cal_texture_info(mlx, &y_ratio, &delta_y);
	//printf("hit.x_pos: %f, hit.dir: %d, distance: %f\n", mlx->hit.x_pos, mlx->hit.hit_dir, mlx->hit.distance);
	// printf("texture width: %d, height: %d\n", (int)(t.height), (int)(t.width));
	// printf("y_ratio: %f, delta_y: %f\n", y_ratio, delta_y);
	while (++y < WIN_Y)
	{
		y_ratio += delta_y;
		if (y_ratio < 0)
			color = mlx->info.celling_color;
		else if (y_ratio >= 1)
			color = mlx->info.floor_color;
		else
			color = t.texture[(int)(t.height * y_ratio)] \
				[(int)(t.width * mlx->hit.x_pos)];
		// printf("y_ratio: %f, delta_y: %f\n", y_ratio, delta_y);
		// printf("texture[%d][%d]\n", (int)(t.height * y_ratio), (int)(t.width * mlx->hit.x_pos));
		// printf("color: %#X\n", color);
		my_mlx_pixel_put(&mlx->img, window_x, y, color);
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
	if (!img_data)
		fail_exit();
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
}
