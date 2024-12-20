#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h> // 이거 errno써도 되려나..
# include <mlx.h>
# include <math.h>
# include "libft.h"


# define WIN_X 1920
# define WIN_Y 1080
# define KEY_EXIT 53 // exit key

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

typedef struct s_info
{
	char		*cub_path;
	int			**map;
	int			map_width;
	int			map_height;
	t_color		floor_color;
	t_color		celling_color;
	t_texture	textures[4];
}	t_info;



typedef struct s_position
{
	double	x; //
	double	y; // 이것도 마우스라 필요없을 수 도?
	double	scope; // 필요 없을 수도
}	t_position;

typedef struct s_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// typedef struct s_complex
// {
// 	double	real;
// 	double	imagin;
// }	t_complex;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			option;
	int			col_op;
	t_position	pos;
	t_data		img;
	t_info		info; // 혹은 t_info *info;
	// t_complex	jcomplex;
}	t_mlx;


#endif
