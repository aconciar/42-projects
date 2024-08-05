/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:32:59 by aconciar          #+#    #+#             */
/*   Updated: 2024/08/05 16:17:49 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_parse_rgb(t_rgb rgb, char *type)
{
	if (rgb.r == -42 || rgb.g == -42 || rgb.b == -42)
		return (ft_printf(2, "Error\nMissing %s color\n", type));
	else
		if (rgb.r < 0 || rgb.r > 255 || rgb.g < 0
			|| rgb.g > 255 || rgb.b < 0 || rgb.b > 255)
			return (ft_printf(2, "Error\nInvalid %s color\n", type));
	return (0);
}

int	ft_parse_texture(t_map map)
{
	if (!map.no.path || !map.so.path || !map.we.path || !map.ea.path)
		return (ft_printf(2, "Error\nMissing texture\n"));
	return (0);
}

int	ft_parsing(t_map *map)
{
	if (ft_parse_rgb(map->ceiling, "ceiling")
		|| ft_parse_rgb(map->floor, "floor"))
		return (1);
	if (ft_parse_texture(*map))
		return (1);
	if (ft_parse_map((*map).map, map))
		return (1);
	return (0);
}
