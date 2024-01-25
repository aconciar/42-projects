/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:00:08 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/09 16:14:15 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image3(t_data *front, int key, int x, int y)
{
	if (front->mat[y][x] == 'V' && key == 'w')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.backspine, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'V' && key == 'a')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.leftspine, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'V' && key == 'd')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.rightspine, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'V' && key == 's')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.frontspine, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'M')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.morte, x * PIXEL, y * PIXEL);
}

void	put_image2(t_data *front, int key, int x, int y)
{
	if (front->mat[y][x] == 'X')
	{
		if (front->moves % 5 == 0 && front->moves != 0)
			mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
				front->img.spinesu, x * PIXEL, y * PIXEL);
		else
			mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
				front->img.spinegiu, x * PIXEL, y * PIXEL);
	}
	if (front->mat[y][x] == 'P' && key == 'w')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.back, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'P' && key == 'a')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.left, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'P' && key == 'd')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.right, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'P' && key == 's')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.front, x * PIXEL, y * PIXEL);
	put_image3(front, key, x, y);
}

void	put_image(t_data *front, int key, int x, int y)
{
	if (front->mat[y][x] == '1')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.wall, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == '0')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.zero, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'C')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.coll, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'E')
	{
		if (front->coll == front->tot_coll)
			mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
				front->img.exit, x * PIXEL, y * PIXEL);
		else
			mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
				front->img.trapdoor, x * PIXEL, y * PIXEL);
	}
	put_image2(front, key, x, y);
}
