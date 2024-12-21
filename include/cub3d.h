/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:39:12 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/22 00:46:31 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// win size
# define WIN_X 800
# define WIN_Y 600

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <mlx.h>
# include <math.h>

# include "../libft/libft.h"
# include "mlx.h"

# define NO 0
# define SO	1
# define WE 2
# define EA 3

typedef struct s_texture
{
	char	*path;
	int		**texture;
	int		width;
	int		height;
}	t_texture;

typedef struct s_person
{
	double	x_pos;
	double	y_pos;
	double	x_dir;
	double	y_dir;
	double	x_camera;
	double	y_camera;
	double	fov;
}	t_person;

typedef struct s_info
{
	char		*cub_path;
	char		**map;
	int			map_width;
	int			map_height;
	int			floor_color;
	int			celling_color;
	t_person	person;
	t_texture	textures[4];
}	t_info;

typedef struct s_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_ray
{
	double	dx;
	double	dy;
	double	delta_x;
	double	delta_y;
	double	x_dist;
	double	y_dist;
	int		x_pos;
	int		y_pos;
	int		x_step;
	int		y_step;
}t_ray;

typedef struct s_hit
{
	int		hit_dir;
	double	distance;
	double	x_pos;
}	t_hit;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;
	t_info		info;
	t_ray		ray;
	t_hit		hit;
	int			key_state;
}	t_mlx;

void	cub3d_parse(t_info *info, char *path);

#endif
