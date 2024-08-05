/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:33:09 by aconciar          #+#    #+#             */
/*   Updated: 2024/07/30 15:16:50 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_var(t_map *map)
{
	map->no.path = NULL;
	map->so.path = NULL;
	map->we.path = NULL;
	map->ea.path = NULL;
	map->door.path = ft_strdup("textures/door.xpm");
	map->map = NULL;
	map->floor.r = -42;
	map->floor.g = -42;
	map->floor.b = -42;
	map->ceiling.r = -42;
	map->ceiling.g = -42;
	map->ceiling.b = -42;
	map->p_x = 0;
	map->p_y = 0;
}

void	ft_init_map(t_map *map, char *arg)
{
	int	fd;
	int	tmp_fd;

	if (arg[ft_strlen(arg) - 1] != 'b' || arg[ft_strlen(arg) - 2] != 'u'
		|| arg[ft_strlen(arg) - 3] != 'c' || arg[ft_strlen(arg) - 4] != '.')
		ft_error("Invalid File Extension");
	fd = open(arg, O_RDONLY);
	tmp_fd = open(arg, O_RDONLY);
	if (fd == -1 || tmp_fd == -1)
		ft_error("Invalid File");
	ft_check_syntax(tmp_fd);
	ft_init_var(map);
	ft_readfile(map, fd);
	close(fd);
	close(tmp_fd);
}
