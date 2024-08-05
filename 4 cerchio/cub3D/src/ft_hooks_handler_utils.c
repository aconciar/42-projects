/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_handler_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:23:28 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/05 16:05:01 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	toggle_door(t_mlx *data, int check_x, int check_y)
{
	if ((int)(data->player->x / T_SIZE) != check_x
		&& (int)(data->player->y / T_SIZE) != check_y)
	{
		if (data->map.map[check_x][check_y] == 'D')
			data->map.map[check_x][check_y] = 'd';
		else if (data->map.map[check_x][check_y] == 'd')
			data->map.map[check_x][check_y] = 'D';
	}
}

void	handle_doors(t_mlx *data)
{
	int		check_x;
	int		check_y;
	double	dir_x;
	double	dir_y;

	dir_x = cos(data->player->angle);
	dir_y = sin(data->player->angle);
	check_y = (int)(data->player->x + dir_x * T_SIZE) / T_SIZE;
	check_x = (int)(data->player->y + dir_y * T_SIZE) / T_SIZE;
	if (data->map.map[check_x][check_y] == 'D'
		|| data->map.map[check_x][check_y] == 'd')
		toggle_door(data, check_x, check_y);
}

int	ft_exit_window(t_mlx *data)
{
	mlx_destroy_image(data->mlx, data->main_img.img);
	mlx_destroy_image(data->mlx, data->map.no.img_ptr);
	mlx_destroy_image(data->mlx, data->map.so.img_ptr);
	mlx_destroy_image(data->mlx, data->map.ea.img_ptr);
	mlx_destroy_image(data->mlx, data->map.we.img_ptr);
	mlx_destroy_image(data->mlx, data->map.door.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite1.img_ptr);
	mlx_destroy_image(data->mlx, data->sprite2.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_matrix(data->map.map);
	free(data->map.no.path);
	free(data->map.so.path);
	free(data->map.ea.path);
	free(data->map.we.path);
	free(data->map.door.path);
	free(data->sprite1.path);
	free(data->sprite2.path);
	free(data->mlx);
	free(data->player);
	exit (1);
}

int	ft_check_collision(t_mlx *data, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = data->player->x + move_x;
	new_y = data->player->y + move_y;
	if (data->map.map[(int)((new_y - P_SIZE) / T_SIZE)]
		[(int)((new_x - P_SIZE) / T_SIZE)] == '1'
		|| data->map.map[(int)((new_y - P_SIZE) / T_SIZE)]
		[(int)((new_x + P_SIZE) / T_SIZE)] == '1'
		|| data->map.map[(int)((new_y + P_SIZE) / T_SIZE)]
		[(int)((new_x - P_SIZE) / T_SIZE)] == '1'
		|| data->map.map[(int)((new_y + P_SIZE) / T_SIZE)]
		[(int)((new_x + P_SIZE) / T_SIZE)] == '1')
		return (1);
	if (data->map.map[(int)((new_y - P_SIZE) / T_SIZE)]
		[(int)((new_x - P_SIZE) / T_SIZE)] == 'D'
		|| data->map.map[(int)((new_y - P_SIZE) / T_SIZE)]
		[(int)((new_x + P_SIZE) / T_SIZE)] == 'D'
		|| data->map.map[(int)((new_y + P_SIZE) / T_SIZE)]
		[(int)((new_x - P_SIZE) / T_SIZE)] == 'D'
		|| data->map.map[(int)((new_y + P_SIZE) / T_SIZE)]
		[(int)((new_x + P_SIZE) / T_SIZE)] == 'D')
		return (1);
	return (0);
}

void	mouse_rotation(t_mlx *data)
{
	int		current_x;
	int		current_y;
	int		delta_x;
	double	move_x;

	mlx_mouse_get_pos(data->mlx, data->win, &current_x, &current_y);
	delta_x = data->player->mouse_x - current_x;
	move_x = delta_x * 0.01;
	data->player->angle -= move_x;
	data->player->mouse_x = current_x;
	if (data->player->mouse_x > WIDTH - 10 || data->player->mouse_x < 10)
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
}
