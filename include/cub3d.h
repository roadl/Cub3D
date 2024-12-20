#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h> // 이거 errno써도 되려나.. MiniLibX에서 잘 처리 안한다고 함.
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct s_texture
{
	char	*path;
	int		*texture;
	int		width;
	int		height;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

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
	double	x_pos; // 직선의 순간 x좌표
	double	y_pos; // 직선의 순간 y좌표
	double	dx;
	double	dy;
	bool	flag; // 0 -> dx가 더큼, 1 -> dy가 더큼
}t_ray;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img;
	t_info		info; // 혹은 t_info *info;
	t_ray		ray;
	int			key_state; // t_key_flag에서 shift 연산
	int test; // 나중에 지우기
}	t_mlx;


#endif
