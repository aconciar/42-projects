/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:13:30 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/12 18:37:07 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(char **map, int count, int a, int l, int p)
{
	t_point	cord;
	int		exit;

	cord.x = 0;
	cord.y = 0;
	exit = 5;
	if (count == 0 || a == l)
		return (1);
	while (map[cord.y])
	{
		while (map[cord.y][cord.x])
		{
			if (map[cord.y][cord.x] != '1' && map[cord.y][cord.x] != 'X'
				&& map[cord.y][cord.x] != 'E' && map[cord.y][cord.x] != 'F')
				return (1);
			if (map[cord.y][cord.x] == 'E')
				exit -= 5;
			if (map[cord.y][cord.x] == 'F')
				p -= 3;
			cord.x++;
		}
		cord.x = 0;
		cord.y++;
	}
	return (exit + p);
}


int	find_p(char **map, t_data *data, int x, int y)
{
	int	count;

	count = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				data->p.x = x;
				data->p.y = y;
			}
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	data->size.x = ft_strlen(map[0]);
	data->size.y = y;
	if (data->size.x != data->p.x && data->size.y != data->p.y)
		flood_fill(map, data->size, data->p);
	return (check_exit(map, count, data->size.x, data->size.y, 3));
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
	while (map[y] && map[y][x++])
	{
		if (map[y][x] != '1')
			return (1);
	}
	while (--y >= 0)
	{
		if (map[y][x] != '1')
			return (1);
	}
	return (0);
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

int	check_map(t_data *front)
{
	int		check;
	int		y;
	char	**tmp;

	y = 0;
	tmp = (char **)malloc (sizeof(char *) * (matlen(front->mat) + 10));
	if (!tmp)
		return (0);
	while (front->mat[y])
	{
		tmp[y] = ft_strdup(front->mat[y]);
		y++;
	}
	tmp[y] = NULL;
	if (size_check(tmp))
		return (free_mat(tmp), 1);
	check = find_p(tmp, front, 0, 0);
	free_mat(tmp);
	return (check);
}
