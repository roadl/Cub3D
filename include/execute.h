/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuyu <yuyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:02:43 by yuyu              #+#    #+#             */
/*   Updated: 2024/12/21 20:35:53 by yuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "cub3d.h"

// win size
# define WIN_X 800
# define WIN_Y 600

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

// map 충돌 방지
# define SAFE_DISTANCE 0.05
# define ALMOSTZERO 1.0e-9

# define PI 3.14159265359
# define FOV (PI / 60)
# define DIV_ANGLE (FOV / WIN_X)

# define MOVE_SPEED 0.05 // 일단 0.01 ~ 0.1 생각해야할듯
# define TURN_SPEED (PI / 180) // 1도 씩 움직임.


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
int		program_end(t_mlx *mlx);
void	error_occur(t_mlx *mlx, char *custom_msg, int e_code);

//==================== execute_hit.c ====================
void	cal_hit_pos(t_mlx *mlx);
void	cal_hit_dir(t_mlx *mlx);
void	cal_hit_parameter(t_mlx *mlx);

//==================== execute_hook.c ====================
int		key_press(int keycode, t_mlx *mlx);
int		key_release(int keycode, t_mlx *mlx);

//==================== execute_move.c ====================
void	ft_move_w(t_mlx *mlx);
void	ft_move_a(t_mlx *mlx);
void	ft_move_s(t_mlx *mlx);
void	ft_move_d(t_mlx *mlx);
void	ft_turn(t_mlx *mlx, char ch);

//==================== execute_raycasting.c ====================
void	render_sceen(t_mlx *mlx);
void	ray_casting(t_mlx *mlx);

#endif
