/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:03:40 by yojin             #+#    #+#             */
/*   Updated: 2024/12/21 21:30:59 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		if (!ft_isspace(line[i++]))
			return (0);
	return (1);
}

char	*free_and_gnl(char *line, int fd)
{
	free(line);
	return (get_next_line(fd));
}

void	fail_exit(void)
{
	perror("cub3d");
	exit(EXIT_FAILURE);
}

void	error_exit(const char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	open_with_check(char *path, int opt)
{
	int	fd;

	fd = open(path, opt);
	if (!fd)
		fail_exit();
	return (fd);
}
