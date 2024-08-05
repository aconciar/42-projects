/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:56:47 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/05 15:57:22 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_draw_border(t_mlx *mlx, int start_x, int start_y, int size)
{
	int	i;
	int	j;
	int	border;

	border = (T_SIZE / DIVISOR) * BORDER_RATIO;
	i = -1;
	while (++i < size + (border * 2))
	{
		j = -1;
		while (++j < size + (border * 2))
		{
			if (i < border || i >= size + border
				|| j < border || j >= size + border)
				ft_pixel_put(&mlx->main_img, start_x + i,
					start_y + j, 0xFFFF00);
			else
				ft_pixel_put(&mlx->main_img, start_x + i,
					start_y + j, 0x000000);
		}
	}
}

static void	ft_draw_tile(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;
	int	cell_size;

	cell_size = T_SIZE / DIVISOR;
	i = -1;
	while (++i < cell_size)
	{
		j = -1;
		while (++j < cell_size)
			ft_pixel_put(&mlx->main_img, x + i, y + j, color);
	}
}

static void	ft_draw_map(t_mlx *mlx, int start_x, int start_y, char **map)
{
	int	i;
	int	j;
	int	map_x;
	int	map_y;
	int	color;

	i = -1;
	while (++i < MINIMAP_SIZE)
	{
		j = -1;
		while (++j < MINIMAP_SIZE)
		{
			map_x = (int)(mlx->player->x / T_SIZE) - MINIMAP_SIZE / 2 + i;
			map_y = (int)(mlx->player->y / T_SIZE) - MINIMAP_SIZE / 2 + j;
			if (map_x >= 0 && map_y >= 0 && map_x < mlx->win_width / T_SIZE
				&& map_y < mlx->win_height / T_SIZE)
			{
				choose_color(map, map_x, map_y, &color);
				ft_draw_tile(mlx, start_x + i * (T_SIZE / DIVISOR),
					start_y + j * (T_SIZE / DIVISOR), color);
			}
		}
	}
}

static void	ft_draw_player(t_mlx *mlx, int msize)
{
	int	i;
	int	j;

	i = -1;
	while (++i < P_SIZE / DIVISOR)
	{
		j = -1;
		while (++j < P_SIZE / DIVISOR)
			ft_pixel_put(&mlx->main_img, (msize / 2) + i + (T_SIZE / DIVISOR),
				(msize / 2) + j + (T_SIZE / DIVISOR), 0xFF0000);
	}
}

void	ft_minimap(t_mlx *mlx, char **map)
{
	int	map_size;
	int	border_size;
	int	start_x;
	int	start_y;

	map_size = MINIMAP_SIZE * (T_SIZE / DIVISOR);
	border_size = (T_SIZE / DIVISOR) * BORDER_RATIO;
	start_x = border_size;
	start_y = border_size;
	ft_draw_border(mlx, start_x, start_y, map_size);
	ft_draw_map(mlx, start_x + border_size, start_y + border_size, map);
	ft_draw_player(mlx, map_size);
}
