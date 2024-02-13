/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:33:00 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/16 19:24:38 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoingnl(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free (left_str);
	return (str);
}

char	**readmap(int map, int cont)
{
	char	*buf;
	char	*str;
	char	**mat;

	buf = (char *)malloc(sizeof(char) * 10000);
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	buf[0] = '\0';
	while (cont > 0)
	{
		cont = read(map, buf, 10000);
		if (cont == -1)
		{
			free(buf);
			return (0);
		}
		buf[cont] = '\0';
		str = ft_strjoingnl(str, buf);
		if (!str)
			return (NULL);
	}
	free(buf);
	mat = ft_split(str, '\n');
	free(str);
	return (mat);
}

char	**map(char *fd)
{
	int		map;
	char	**mat;

	map = open(fd, O_RDONLY);
	mat = readmap(map, 1);
	return (mat);
}

int	matlen(char **mat)
{
	int	y;

	y = 0;
	while (mat[y])
		y++;
	return (y);
}
