/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:52:19 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/05 15:39:49 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_move_sideways(t_mlx *data, double move_x, double move_y)
{
	move_x = -MOVE_SPEED * sin(data->player->angle);
	move_y = MOVE_SPEED * cos(data->player->angle);
	if (data->player->d && ft_check_collision(data, move_x, 0) == 0)
		data->player->x += move_x;
	if (data->player->d && ft_check_collision(data, 0, move_y) == 0)
		data->player->y += move_y;
	if (data->player->a && ft_check_collision(data, -move_x, 0) == 0)
		data->player->x -= move_x;
	if (data->player->a && ft_check_collision(data, 0, -move_y) == 0)
		data->player->y -= move_y;
}

void	ft_move_player(t_mlx *data)
{
	double	move_x;
	double	move_y;

	move_x = MOVE_SPEED * cos(data->player->angle);
	move_y = MOVE_SPEED * sin(data->player->angle);
	if (data->player->w && ft_check_collision(data, move_x, 0) == 0)
		data->player->x += move_x;
	if (data->player->w && ft_check_collision(data, 0, move_y) == 0)
		data->player->y += move_y;
	if (data->player->s && ft_check_collision(data, -move_x, 0) == 0)
		data->player->x -= move_x;
	if (data->player->s && ft_check_collision(data, 0, -move_y) == 0)
		data->player->y -= move_y;
	if (data->player->a || data->player->d)
		ft_move_sideways(data, move_x, move_y);
}

/* void ft_move_player(t_mlx *data)
{
    double move_x = 0;
    double move_y = 0;
    double angle = data->player->angle;
    double speed = MOVE_SPEED * data->delta_time;

    // Forward/Backward movement
    if (data->player->w || data->player->s)
    {
        move_x += speed * cos(angle) * (data->player->w ? 1 : -1);
        move_y += speed * sin(angle) * (data->player->w ? 1 : -1);
    }

    // Sideways movement
    if (data->player->a || data->player->d)
    {
        move_x += speed * sin(angle) * (data->player->d ? -1 : 1);
        move_y += speed * cos(angle) * (data->player->d ? 1 : -1);
    }

    // Check collision for combined movement
    if (ft_check_collision(data, move_x, move_y) == 0)
    {
        data->player->x += move_x;
        data->player->y += move_y;

        // Round the position to reduce floating-point errors
        data->player->x = round(data->player->x * 1000.0) / 1000.0;
        data->player->y = round(data->player->y * 1000.0) / 1000.0;
    }
} */

int	ft_rotate_player(t_mlx *data)
{
	if (data->player->turn_left == 1)
		data->player->angle -= 0.06;
	if (data->player->turn_right == 1)
		data->player->angle += 0.06;
	if (data->player->angle < 0)
		data->player->angle += 2 * PI;
	if (data->player->angle > 2 * PI)
		data->player->angle -= 2 * PI;
	return (0);
}
