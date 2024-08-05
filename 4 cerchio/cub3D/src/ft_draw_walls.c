/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:59:45 by aconciar          #+#    #+#             */
/*   Updated: 2024/08/05 15:57:44 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_texture	*choose_texture(t_line *ray, t_mlx *data, int side)
{
	t_texture	*texture;

	if (ray->hit == 1)
	{
		if (side == 0)
		{
			if (ray->dir_x > 0)
				texture = &data->map.ea;
			else
				texture = &data->map.we;
		}
		else
		{
			if (ray->dir_y > 0)
				texture = &data->map.so;
			else
				texture = &data->map.no;
		}
	}
	else
		texture = &data->map.door;
	return (texture);
}

void	ft_draw_walls(t_line *ray, t_image *img, int k, t_mlx *data)
{
	int			j;
	t_wall		wall;
	t_texture	*t;

	t = choose_texture(ray, data, ray->side);
	wall.wall_height = (T_SIZE * HEIGHT)
		/ (ray->distance * cos(ray->angle - data->player->angle));
	if (ray->side == 0)
		wall.wall_x = ray->y_0 + ray->distance * ray->dir_y;
	else
		wall.wall_x = ray->x_0 + ray->distance * ray->dir_x;
	wall.tex_x = (int)(wall.wall_x * t->width / T_SIZE) % t->width;
	j = 0;
	while (j < wall.wall_height)
	{
		wall.pixel_y = (j + HEIGHT / 2 - wall.wall_height / 2);
		if (wall.pixel_y >= 0 && wall.pixel_y < HEIGHT)
		{
			wall.tex_y = j * t->height / wall.wall_height;
			wall.color = t->data[wall.tex_y * t->width + wall.tex_x];
			ft_pixel_put(img, k, wall.pixel_y, wall.color);
		}
		j++;
	}
}
