/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:03:19 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/12 18:12:20 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return ;
	if (tab[begin.y][begin.x] == '0' || tab[begin.y][begin.x] == 'C')
	{
		tab[begin.y][begin.x] = 'X';
		flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
		flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
		flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
		flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	}
	if (tab[begin.y][begin.x] == 'P')
	{
		tab[begin.y][begin.x] = 'F';
		flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
		flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
		flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
		flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	}
	return ;
}

