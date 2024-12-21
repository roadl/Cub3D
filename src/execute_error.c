/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:16:41 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/21 17:50:55 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	program_end(t_mlx *mlx) // 정상종료
{
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

void	error_occur(t_mlx *mlx, char *custom_msg, int e_code) // 문제 발생
{
	const char	*error_msg = strerror(errno); // 추후 수정 필요할 듯. errno 어캐 할건지..

	if (custom_msg)
		ft_putendl_fd(custom_msg, 2);
	else
		ft_putendl_fd(error_msg, 2);
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (e_code)
		exit(e_code);
	else
		exit(errno);
}
