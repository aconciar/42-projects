/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:44:44 by aconciar          #+#    #+#             */
/*   Updated: 2024/07/29 15:47:33 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_assing_rgb_value(t_rgb *rgb, char *trimmed)
{
	if (rgb->r != -42)
		return (1);
	rgb->r = ft_atoi(trimmed);
	while (*trimmed != '\0' && *trimmed != ',')
		trimmed++;
	if (*trimmed == '\0')
		return (0);
	trimmed++;
	rgb->g = ft_atoi(trimmed);
	while (*trimmed != '\0' && *trimmed != ',')
		trimmed++;
	if (*trimmed == '\0')
		return (0);
	trimmed++;
	rgb->b = ft_atoi(trimmed);
	return (0);
}

static int	ft_assing_textures(char **texture, char *trimmed)
{
	if (*texture != NULL)
		return (1);
	*texture = ft_strdup(trimmed);
	return (0);
}

static int	ft_assing_value(t_map *map, char *trimmed)
{
	if (trimmed[0] == 'N' && trimmed[1] == 'O')
		if (ft_assing_textures(&map->no.path, trimmed + 3) != 0)
			return (1);
	if (trimmed[0] == 'S' && trimmed[1] == 'O')
		if (ft_assing_textures(&map->so.path, trimmed + 3) != 0)
			return (1);
	if (trimmed[0] == 'W' && trimmed[1] == 'E')
		if (ft_assing_textures(&map->we.path, trimmed + 3) != 0)
			return (1);
	if (trimmed[0] == 'E' && trimmed[1] == 'A')
		if (ft_assing_textures(&map->ea.path, trimmed + 3) != 0)
			return (1);
	if (trimmed[0] == 'F' && trimmed[1] == ' ')
		if (ft_assing_rgb_value(&map->floor, trimmed + 2) != 0)
			return (1);
	if (trimmed[0] == 'C' && trimmed[1] == ' ')
		if (ft_assing_rgb_value(&map->ceiling, trimmed + 2) != 0)
			return (1);
	return (0);
}

static void	ft_readmap(t_map *map, int fd, char *line)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	map->map = ft_calloc(size, sizeof(char *));
	while (1)
	{
		if (line == NULL)
			line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\0')
		{
			map->map = ft_realloc(map->map, size * sizeof(char *),
					((i + 2) * sizeof(char *)));
			size = i + 2;
			map->map[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = NULL;
	}
	map->map[i] = NULL;
	get_next_line(-42);
}

void	ft_readfile(t_map *map, int fd)
{
	char	*line;
	char	*trimmed;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		trimmed = ft_strtrim(line, " \t\v\f\r\n");
		if (ft_isdigit(trimmed[0]) || !trimmed)
		{
			free(trimmed);
			break ;
		}
		free(line);
		if (ft_assing_value(map, trimmed) != 0)
		{
			free(trimmed);
			get_next_line(-42);
			ft_free_struct(map);
			ft_error("Textures Duplicates");
		}
		free(trimmed);
	}
	ft_readmap(map, fd, line);
}
