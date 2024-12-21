#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

// parse.c
void	cub3d_parse(t_info *info, char *path);

// util.c
int		is_empty(char *line);
char	*free_and_gnl(char *line, int fd);
void	fail_exit(void);
void	error_exit(const char *error_msg);
int		open_with_check(char *path, int opt);

// util2.c
void	init_info(t_info *info);
void	cal_texture_info(t_mlx *mlx, double *y_ratio, double *delta_y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//check.c
void	check_cub_file(char *path);
void	check_xpm_file(char *path);
void	check_map_valid(t_info *info);
void	check_color_valid(char **strs);
void	check_info_valid(t_info *info);

//map.c
int		is_line_map(char *line);
void	parse_map(t_info *info, char *path);

//map_util.c
int		is_valid_point(t_info *info, int x, int y);
int		is_map_char(char c);
int		is_line_map(char *line);
int		cal_width(char *line);
void	copy_line(char *map_row, char *line, int width);

//texture.c
//void	print_texture_line(t_mlx *mlx, double x_ratio, int distance, int wall, int window_x);
void	texture_mapping(t_mlx *mlx, int window_x);
void	init_textures(t_mlx *mlx);

//debug.c
void	print_map(t_info *info);
void	print_info(t_info *info);
void	print_player(t_person p);
void	print_texture_window(t_mlx *mlx);
void	leaks(void);

#endif