/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:13:33 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/05 14:16:24 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_is_wall(int x, int y, t_mlx *data)
{
	int	map_x;
	int	map_y;

	map_x = x / T_SIZE;
	map_y = y / T_SIZE;
	if (x < 0 || y < 0)
		return (0);
	if (map_x >= data->win_width / T_SIZE || map_y >= data->win_height / T_SIZE
		|| map_x < 0 || map_y < 0)
		return (0);
	if (data->map.map[map_y][map_x] == '1')
		return (1);
	else if (data->map.map[map_y][map_x] == 'D')
		return (2);
	return (0);
}

static void	ft_collision_utils(t_dda *dda, int *map_coordinate, int flag)
{
	if (flag == 0)
	{
		dda->side_dist_x += dda->delta_dist_x;
		*map_coordinate += dda->step_x;
		dda->side = 0;
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		*map_coordinate += dda->step_y;
		dda->side = 1;
	}
}

static int	ft_collision(t_dda *dda, int map_x, int map_y, t_mlx *data)
{
	while (1)
	{
		if (dda->dx < 0)
			dda->side_dist_x = (dda->x - map_x * T_SIZE) * dda->delta_dist_x;
		else
			dda->side_dist_x = (map_x * T_SIZE + T_SIZE - dda->x)
				* dda->delta_dist_x;
		if (dda->dy < 0)
			dda->side_dist_y = (dda->y - map_y * T_SIZE) * dda->delta_dist_y;
		else
			dda->side_dist_y = (map_y * T_SIZE + T_SIZE - dda->y)
				* dda->delta_dist_y;
		if (dda->side_dist_x < dda->side_dist_y)
			ft_collision_utils(dda, &map_x, 0);
		else
			ft_collision_utils(dda, &map_y, 1);
		if (ft_is_wall(map_x * T_SIZE, map_y * T_SIZE, data) == 1)
			return (1);
		else if (ft_is_wall(map_x * T_SIZE, map_y * T_SIZE, data) == 2)
			return (2);
	}
	return (0);
}

static void	ft_init_dda_data(t_dda *dda, t_line *line)
{
	dda->x = line->x_0;
	dda->y = line->y_0;
	dda->dx = line->x_1 - line->x_0;
	dda->dy = line->y_1 - line->y_0;
	dda->delta_dist_x = fabs(1 / (double)dda->dx);
	dda->delta_dist_y = fabs(1 / (double)dda->dy);
	if (dda->dx < 0)
		dda->step_x = -1;
	else
		dda->step_x = 1;
	if (dda->dy < 0)
		dda->step_y = -1;
	else
		dda->step_y = 1;
}

int	ft_dda(t_line *line, t_mlx *data)
{
	t_dda	dda;
	int		map_x;
	int		map_y;

	ft_init_dda_data(&dda, line);
	map_x = (int)(dda.x / T_SIZE);
	map_y = (int)(dda.y / T_SIZE);
	line->hit = ft_collision(&dda, map_x, map_y, data);
	dda.x_inc = dda.dx / sqrt(pow(dda.dx, 2) + pow(dda.dy, 2));
	dda.y_inc = dda.dy / sqrt(pow(dda.dx, 2) + pow(dda.dy, 2));
	while (data->map.map[(int)dda.y / T_SIZE][(int)dda.x / T_SIZE] != '1'
		&& data->map.map[(int)dda.y / T_SIZE][(int)dda.x / T_SIZE] != 'D')
	{
		if (dda.x < 0.00001 || dda.y < 0.00001
			|| dda.x >= data->win_width - 0.00001
			|| dda.y >= data->win_height - 0.00001)
			break ;
		dda.x += dda.x_inc;
		dda.y += dda.y_inc;
	}
	line->distance = sqrt(pow(dda.x - line->x_0, 2)
			+ pow(dda.y - line->y_0, 2));
	return (dda.side);
}
