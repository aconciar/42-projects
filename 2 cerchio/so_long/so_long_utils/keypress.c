/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:44:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/09 17:58:42 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	press_ws2(int key, t_data *front, int a)
{
	if (front->mat[front->p.y + a][front->p.x] == 'C')
		front->coll++;
	if (front->mat[front->p.y + a][front->p.x] == 'X'
		&& front->moves % 5 == 0)
	{
		front->mat[front->p.y + a][front->p.x] = 'M';
		front->mat[front->p.y][front->p.x] = '0';
		front->morte = 1;
		rend_map(front, key);
		return (0);
	}
	if (front->mat[front->p.y + a][front->p.x] == 'X')
		front->mat[front->p.y + a][front->p.x] = 'V';
	else
		front->mat[front->p.y + a][front->p.x] = 'P';
	if (front->mat[front->p.y][front->p.x] == 'V')
		front->mat[front->p.y][front->p.x] = 'X';
	else
		front->mat[front->p.y][front->p.x] = '0';
	if (key == 'w')
		front->p.y--;
	else
		front->p.y++;
	rend_map(front, key);
	return (0);
}

static int	press_ws(int key, t_data *front, int a)
{
	if (front->mat[front->p.y + a][front->p.x] != '1' &&
			front->mat[front->p.y + a][front->p.x] != 'E' &&
				front->morte != 1)
	{
		front->moves++;
		press_ws2(key, front, a);
	}
	else if (front->mat[front->p.y + a][front->p.x] == 'E')
		if (front->coll == front->tot_coll)
			return (destroy_window(front));
	return (0);
}

static int	press_ad2(int key, t_data *front, int i)
{
	if (front->mat[front->p.y][front->p.x + i] == 'C')
		front->coll++;
	if (front->mat[front->p.y][front->p.x + i] == 'X' &&
		front->moves % 5 == 0)
	{
		front->mat[front->p.y][front->p.x + i] = 'M';
		front->mat[front->p.y][front->p.x] = '0';
		front->morte = 1;
		rend_map(front, key);
		return (0);
	}
	if (front->mat[front->p.y][front->p.x + i] == 'X')
		front->mat[front->p.y][front->p.x + i] = 'V';
	else
		front->mat[front->p.y][front->p.x + i] = 'P';
	if (front->mat[front->p.y][front->p.x] == 'P')
		front->mat[front->p.y][front->p.x] = '0';
	else
		front->mat[front->p.y][front->p.x] = 'X';
	if (key == 'a')
		front->p.x--;
	else
		front->p.x++;
	rend_map(front, key);
	return (0);
}

static int	press_ad(int key, t_data *front, int i)
{
	if (front->mat[front->p.y][front->p.x + i] != '1' &&
			front->mat[front->p.y][front->p.x + i] != 'E' &&
				front->morte != 1)
	{
		front->moves++;
		press_ad2(key, front, i);
	}
	else if (front->mat[front->p.y][front->p.x + i] == 'E')
		if (front->coll == front->tot_coll)
			return (destroy_window(front));
	return (0);
}

int	ft_keypress(int key, t_data *front)
{
	char	*str;

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
	if (front->morte == 1)
	{
		str = ft_strdup("YOU ARE DEAD, press ESC to leave");
		mlx_string_put(front->mlx_ptr, front->win_ptr, 100, 30, 0xFF0000, str);
		free(str);
	}
	return (0);
}
