/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:30:53 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/05 16:00:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_ray(t_line *line, t_mlx *info, double angle)
{
	double	dof;

	dof = sqrt(pow(info->win_width, 2) + pow(info->win_height, 2));
	line->x_0 = info->player->x + (P_SIZE / 2);
	line->y_0 = info->player->y + (P_SIZE / 2);
	line->dir_x = cos(angle);
	line->dir_y = sin(angle);
	line->hit = 0;
	line->x_1 = line->x_0 + line->dir_x * dof;
	line->y_1 = line->y_0 + line->dir_y * dof;
	line->angle = angle;
	line->distance = dof;
	line->side = 0;
}

static void	ft_draw_rays_in_fov(t_mlx *data, t_image *img)
{
	t_line	ray;
	double	start_angle;
	double	fov;
	double	current_angle;
	int		k;

	fov = ft_deg_to_rad(60);
	k = 0;
	start_angle = data->player->angle - fov / 2;
	while (k < WIDTH)
	{
		current_angle = start_angle + k * (fov / WIDTH);
		ft_init_ray(&ray, data, current_angle);
		ray.angle = current_angle;
		ray.side = ft_dda(&ray, data);
		ft_draw_walls(&ray, img, k, data);
		k++;
	}
}

void	ft_draw_floor_ceiling(t_mlx *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT / 2)
			ft_pixel_put(&data->main_img, i, j, data->map.ceiling.color);
	}
	i = -1;
	while (++i < WIDTH)
	{
		j = (HEIGHT / 2) - 1;
		while (++j < HEIGHT)
			ft_pixel_put(&data->main_img, i, j, data->map.floor.color);
	}
}

void	ft_draw_sprite(t_mlx *data, int x_off, int y_off)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < data->curr_sprite->height)
	{
		x = 0;
		while (x < data->curr_sprite->width)
		{
			color = data->curr_sprite->data[y * data->curr_sprite->width + x];
			if ((color & 0xFF000000) != 0xFF000000)
				ft_pixel_put(&data->main_img, x + x_off, y + y_off, color);
			x++;
		}
		y++;
	}
}

int	ft_start_game(t_mlx *data)
{
	int	hand_x;
	int	hand_y;

	ft_move_player(data);
	if ((data->player->w || data->player->s
			|| data->player->a || data->player->d) && BONUS == 1)
		ft_animation(data);
	ft_rotate_player(data);
	ft_draw_floor_ceiling(data);
	ft_draw_rays_in_fov(data, &data->main_img);
	if (BONUS == 1)
	{
		ft_minimap(data, data->map.map);
		mouse_rotation(data);
		hand_x = WIDTH / 4 + data->curr_sprite->width;
		hand_y = HEIGHT - data->curr_sprite->height;
		ft_draw_sprite(data, hand_x, hand_y);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->main_img.img, 0, 0);
	return (0);
}
