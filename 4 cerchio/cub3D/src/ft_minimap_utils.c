/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:55:27 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/05 16:23:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	choose_color(char **map, int map_x, int map_y, int *color)
{
	if (map[map_y][map_x] == '1')
		*color = 0x808080;
	else if (map[map_y][map_x] == 'D')
		*color = 0xFF0000;
	else if (map[map_y][map_x] == 'd')
		*color = 0x00FF00;
	else if (map[map_y][map_x] != '1')
		*color = 0xFFFFFF;
}
