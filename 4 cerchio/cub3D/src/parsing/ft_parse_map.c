/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:52:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/08/01 14:59:46 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_check_map(char **map, t_map *data, int y, int flag)
{
	int	x;

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] && map[y][x] != '1' && map[y][x] != '0'
				&& map[y][x] != '?' && map[y][x] != 'D')
			{
				if (map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'W' || map[y][x] == 'E')
				{
					data->p_x = x;
					data->p_y = y;
					flag--;
				}
				if (flag != 0)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (flag);
}

static int	ft_check_lateral_borders(char **map, int rows)
{
	int	x;
	int	y;

	y = 0;
	while (y < rows)
	{
		if (map[y][0] != '1' && map[y][0] != '?')
			return (1);
		x = 0;
		while (map[y][x + 1])
			x++;
		if (map[y][x] != '1' && map[y][x] != '?')
			return (1);
		y++;
	}
	return (0);
}

static int	ft_check_borders(char **map, int rows)
{
	int	x;

	x = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1' && map[0][x] != '?')
			return (1);
		x++;
	}
	x = 0;
	while (map[rows - 1][x])
	{
		if (map[rows - 1][x] != '1' && map[rows - 1][x] != '?')
			return (1);
		x++;
	}
	if (ft_check_lateral_borders(map, rows) != 0)
		return (1);
	return (0);
}

static void	ft_fill_spaces(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_isspace(map[y][x]))
				map[y][x] = '?';
			x++;
		}
		y++;
	}
}

int	ft_parse_map(char **map, t_map *data)
{
	int	ret;

	if (map[0] == NULL)
		return (ft_printf(2, "Error\nMissing map\n"));
	ft_fill_spaces(map);
	ret = ft_check_borders(map, ft_matlen(map));
	ret += ft_check_map(map, data, 0, 1);
	if (ret)
		ft_printf(2, "Error\nInvalid map\n");
	return (ret);
}
