/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojin <yojin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:05:07 by yojin             #+#    #+#             */
/*   Updated: 2024/12/20 21:05:56 by yojin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_info(t_info *info)
{
	int	i;

	i = 0;
	info->floor_color.r = -1;
	info->celling_color.r = -1;
	while (i < 4)
		info->textures[i++].path = NULL;
	info->map_width = 0;
	info->map_height = 0;
	info->person.x_dir = 0;
	info->person.y_dir = 0;
	info->person.x_pos = -1;
	info->person.y_pos = -1;
}
