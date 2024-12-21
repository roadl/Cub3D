/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:20:20 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/22 00:30:07 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_EXIT)
		program_end(mlx);
	if (keycode == KEY_W)
		mlx->key_state |= W_STATE;
	if (keycode == KEY_A)
		mlx->key_state |= A_STATE;
	if (keycode == KEY_S)
		mlx->key_state |= S_STATE;
	if (keycode == KEY_D)
		mlx->key_state |= D_STATE;
	if (keycode == KEY_LEFT)
		mlx->key_state |= LEFT_STATE;
	if (keycode == KEY_RIGHT)
		mlx->key_state |= RIGHT_STATE;
	return (0);
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		mlx->key_state &= ~W_STATE;
	if (keycode == KEY_A)
		mlx->key_state &= ~A_STATE;
	if (keycode == KEY_S)
		mlx->key_state &= ~S_STATE;
	if (keycode == KEY_D)
		mlx->key_state &= ~D_STATE;
	if (keycode == KEY_LEFT)
		mlx->key_state &= ~LEFT_STATE;
	if (keycode == KEY_RIGHT)
		mlx->key_state &= ~RIGHT_STATE;
	return (0);
}
