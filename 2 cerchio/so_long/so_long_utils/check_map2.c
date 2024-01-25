/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:54:04 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/18 16:54:11 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall2(char **map, int x, int y)
{
	while (map[y][x])
	{
		if (map[y][x] != '1')
			return (1);
		x++;
	}
	x--;
	while (y >= 0)
	{
		if (map[y][x] != '1')
			return (1);
		y--;
	}
	return (0);
}

int	check_wall(char **map, int x, int y)
{
	while (map[0][x])
	{
		if (map[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (map[y])
	{
		if (map[y][x] != '1')
			return (1);
		y++;
	}
	y--;
	return (check_wall2 (map, x, y));
}

int	size_check(char **mat)
{
	t_point	c;
	int		i;

	c.x = 0;
	c.y = 0;
	i = ft_strlen(mat[c.y]);
	while (mat[c.y])
	{
		while (mat[c.y][c.x])
			c.x++;
		if (c.x != i)
			return (1);
		c.x = 0;
		c.y++;
	}
	return (check_wall(mat, 0, 1));
}
