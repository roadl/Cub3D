/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:02:43 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/20 17:17:49 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "cub3d.h"

# define PI 3.14159265359

// win size
# define WIN_X 1920
# define WIN_Y 1080

// x11 event
# define X_EVNET_KEY_PRESS 2
# define X_EVNET_KEY_RELEASE 3
# define X_EVNET_EXIT 17

// key number
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_EXIT 53 // exit key
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef enum e_key_flag
{
	W_STATE = 1,
	A_STATE = 1 << 1,
	S_STATE = 1 << 2,
	D_STATE = 1 << 3,
	LEFT_STATE = 1 << 4,
	RIGHT_STATE = 1 << 5
}	t_key_flag;

//==================== execute_error.c ====================
void	program_end(t_mlx *mlx);
void	error_occur(t_mlx *mlx, char *custom_msg, int e_code);

//==================== execute_hook.c ====================
int		key_press(int keycode, t_mlx *mlx);
int		key_release(int keycode, t_mlx *mlx);

#endif
