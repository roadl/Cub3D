/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:29:36 by yojin             #+#    #+#             */
/*   Updated: 2024/12/21 20:02:24 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#define WIN_HEIGHT	720
#define OFFSET		1
#define	MAX			340

void	print_texture_line(t_mlx *mlx, double x_ratio, int distance, int wall, int window_x)
{
	t_texture	t;
	int			y;
	double		wall_height;
	double		y_ratio;
	int			color;
	double		delta_y;

	y = -1;
	t = mlx->info.textures[wall];
	wall_height = (double)WIN_HEIGHT * 2 / (distance + 1);
	y_ratio = -(WIN_HEIGHT - wall_height) / 2 / wall_height;
	delta_y = 1 / wall_height;
	while (++y < WIN_HEIGHT)
	{
		y_ratio += delta_y;
		if (y_ratio < 0)
			color = mlx->info.celling_color;
		else if (y_ratio >= 1)
			color = mlx->info.floor_color;
		else
			color = t.texture[(int)(t.height * y_ratio)][(int)(t.width * x_ratio)];
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, window_x, y, color);
	}
}

// void	print_texture_line(t_mlx *mlx, double x_ratio, int distance, int wall, int window_x)
// {
// 	t_texture	t;
// 	int			y;
// 	double		wall_height;
// 	double		y_ratio;
// 	int			color;

// 	y = -1;
// 	t = mlx->info.textures[wall];
// 	wall_height = (double)WIN_HEIGHT * 2 / (distance + 1);
// 	printf("wall_height: %f\n", wall_height);
// 	while (++y < WIN_HEIGHT)
// 	{
// 		y_ratio = (y - (WIN_HEIGHT - wall_height) / 2) / wall_height;
// 		printf("x_ratio: %f, y_ratio: %f\n", x_ratio, y_ratio);
// 		if (y_ratio < 0)
// 			color = mlx->info.celling_color;
// 		else if (y_ratio >= 1)
// 			color = mlx->info.floor_color;
// 		else
// 			color = t.texture[(int)(t.height * y_ratio)][(int)(t.width * x_ratio)];
// 		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, window_x, y, color);
// 	}
// }

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
