#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
// # include <errno.h> // 이거 errno써도 되려나.. MiniLibX에서 잘 처리 안한다고 함.
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
	double	x_pos; // SAFE_DISTANCE ~ (map_width - SAFE_DISTANCE)
	double	y_pos; // SAFE_DISTANCE ~ (map_height - SAFE_DISTANCE)
	double	x_dir; // normal vector
	double	y_dir; // normal vectors
} t_person;

typedef struct s_info
{
	char		*cub_path;
	// char		**map;
	char		map[40][40]; // test
	int			map_width;
	int			map_height;
	t_color		floor_color;
	t_color		celling_color;
	t_texture	textures[4];
	t_person	person;
}	t_info;

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
	double	dx; // ray 방향
	double	dy;
	double	delta_x; // x하나 증가시키기 위해 가야하는 거리의 비율
	double	delta_y; // y하나 증가시키기 위해 가야하는 거리의 비율
	double	x_dist; // 거리
	double	y_dist;
	int		x_pos; // map상 위치
	int		y_pos;
	int		x_step; // x_map 이동 방향.
	int		y_step; // y_map 이동 방향.
}t_ray;

typedef struct s_hit
{
	int	hit_dir; // w,a,s,d => 0,1,2,3
	int	distance;
	int	x_pos; // texture coordinate
}	t_hit;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;
	t_info		info; // 혹은 t_info *info;
	t_ray		ray;
	t_hit		hit;
	int			key_state; // t_key_flag에서 shift 연산
	int test; // 나중에 지우기
}	t_mlx;

void	cub3d_parse(t_info *info, char *path);

#endif
