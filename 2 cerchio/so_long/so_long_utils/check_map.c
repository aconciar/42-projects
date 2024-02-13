/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:13:30 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/18 16:53:48 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(char **map, int p)
{
	t_point	cord;
	int		exit;

	cord.x = 0;
	cord.y = 0;
	exit = 5;
	while (map[cord.y])
	{
		while (map[cord.y][cord.x])
		{
			if (map[cord.y][cord.x] != '1' && map[cord.y][cord.x] != 'K'
				&& map[cord.y][cord.x] != 'E' && map[cord.y][cord.x] != 'F'
				&& map[cord.y][cord.x] != 'X')
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
	data->tot_coll = 0;
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
				data->tot_coll++;
			x++;
		}
		x = 0;
		y++;
	}
	data->size.x = ft_strlen(map[0]);
	data->size.y = y;
	if (data->tot_coll == 0 || data->size.x == data->size.y)
		return (1);
	if (data->size.x != data->p.x && data->size.y != data->p.y)
		flood_fill(map, data->size, data->p);
	return (check_exit(map, 3));
}

int	check_map(t_data *front)
{
	int		check;
	int		y;
	char	**tmp;

	front->morte = 0;
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
