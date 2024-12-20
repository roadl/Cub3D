#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# include "libft.h"
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

#endif