/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:06:03 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/01 15:02:42 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_mouse_hook(int button, int x, int y, t_mlx *data)
{
	x = WIDTH / 2;
	y = HEIGHT / 2;
	if (button == TOGGLE_DOOR)
		handle_doors(data);
	if (button == RECENTER)
		mlx_mouse_move(data->mlx, data->win, x, y);
	return (0);
}

int	ft_button_down(int key, t_mlx *data)
{
	if (key == ESCAPE)
		ft_exit_window(data);
	if (key == FORWARD)
		data->player->w = 1;
	if (key == BACKWARD)
		data->player->s = 1;
	if (key == RIGHT)
		data->player->d = 1;
	if (key == LEFT)
		data->player->a = 1;
	if (key == R_LEFT)
		data->player->turn_left = 1;
	if (key == R_RIGHT)
		data->player->turn_right = 1;
	if (key == TOGGLE_DOOR_KEY)
		handle_doors(data);
	if (key == RECENTER_KEY)
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	ft_button_up(int key, t_mlx *data)
{
	if (key == FORWARD)
		data->player->w = 0;
	if (key == BACKWARD)
		data->player->s = 0;
	if (key == RIGHT)
		data->player->d = 0;
	if (key == LEFT)
		data->player->a = 0;
	if (key == R_LEFT)
		data->player->turn_left = 0;
	if (key == R_RIGHT)
		data->player->turn_right = 0;
	return (0);
}
