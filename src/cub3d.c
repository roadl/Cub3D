/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:09:47 by yojin             #+#    #+#             */
/*   Updated: 2024/12/20 21:14:34 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"

int	main(int argc, char **argv)
{
	t_info	info;

	atexit(leaks);
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Arguemnt count must be 2\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	cub3d_parse(&info, argv[1]);
	exit(EXIT_SUCCESS);
	return (0);
}
