/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:44:56 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/07 19:00:47 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_data *front)
{
	mlx_destroy_image(front->mlx_ptr, front->img.front);
	mlx_destroy_image(front->mlx_ptr, front->img.zero);
	mlx_destroy_image(front->mlx_ptr, front->img.back);
	mlx_destroy_image(front->mlx_ptr, front->img.coll);
	mlx_destroy_image(front->mlx_ptr, front->img.exit);
	mlx_destroy_image(front->mlx_ptr, front->img.left);
	mlx_destroy_image(front->mlx_ptr, front->img.right);
	mlx_destroy_image(front->mlx_ptr, front->img.wall);
	free_mat(front->mat);
}

int	destroy_window(t_data *front)
{
	mlx_destroy_window(front->mlx_ptr, front->win_ptr);
	free_img(front);
	mlx_destroy_display(front->mlx_ptr);
	free(front->mlx_ptr);
	exit(0);
	return (0);
}

static int	press_ws(int key, t_data *front, int a)
{
	if (front->mat[front->p.y + a][front->p.x] != '1')
	{
		if (front->mat[front->p.y + a][front->p.x] == 'C')
			front->coll++;
		if (front->mat[front->p.y + a][front->p.x] == 'E')
			return (destroy_window(front));
		front->mat[front->p.y + a][front->p.x] = 'P';
		front->mat[front->p.y][front->p.x] = '0';
		if (key == 'w')
			front->p.y--;
		else
			front->p.y++;
		rend_map(front, key);
	}
	return (0);
}

static int	press_ad(int key, t_data *front, int i)
{
	if (front->mat[front->p.y][front->p.x + i] != '1')
	{
		if (front->mat[front->p.y][front->p.x + i] == 'C')
			front->coll++;
		if (front->mat[front->p.y][front->p.x + i] == 'E')
			return (destroy_window(front));
		front->mat[front->p.y][front->p.x + i] = 'P';
		front->mat[front->p.y][front->p.x] = '0';
		if (key == 'a')
			front->p.x--;
		else
			front->p.x++;
		rend_map(front, key);
	}
	return (0);
}

int	ft_keypress(int key, t_data *front)
{
	(void)front;
	if (key == XK_Escape)
		return (destroy_window(front));
	if (key == 'w')
		press_ws(key, front, -1);
	if (key == 'a')
		press_ad(key, front, -1);
	if (key == 'd')
		press_ad(key, front, 1);
	if (key == 's')
		press_ws(key, front, 1);
	return (0);
}
