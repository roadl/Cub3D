#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

// parse.c
void	cub3d_parse(t_info *info, char *path);
void	check_file(char *path);

// util.c
int		is_empty(char *line);
char	*free_and_gnl(char *line, int fd);
void	fail_exit(void);
void	error_exit(const char *error_msg);
int		open_with_check(char *path, int opt);

//check.c
void	check_file(char *path);
void	check_path_valid(char *path);
void	check_map_valid(t_info *info);
void	check_color_valid(char **strs);
void	check_info_valid(t_info *info);

//map.c
int		is_line_map(char *line);
void	parse_map(t_info *info, char *path);

//debug.c
void	print_map(t_info *info);
void	print_info(t_info *info);

#endif