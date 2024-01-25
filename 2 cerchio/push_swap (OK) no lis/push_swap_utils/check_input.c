/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/23 17:08:27 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoingnl(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (left_str == NULL)
		left_str = ft_calloc(1, 1);
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
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free (left_str);
	return (str);
}

void	free_mat(char **mat)
{
	int	y;

	y = 0;
	while (mat[y])
	{
		free(mat[y]);
		y++;
	}
	free(mat);
}

int	is_dup(char **mat, int a, int y)
{
	int	n1;
	int	n2;

	n1 = atoi(mat[a]);
	n2 = atoi(mat[y]);
	return (n1 - n2);
}

int	ft_dup(char **mat, int y)
{
	int	a;

	a = y;
	y++;
	while (mat[y])
	{
		if (is_dup(mat, a, y) == 0)
			return (1);
		y++;
	}
	return (0);
}

int	check_input(char *str)
{
	char	**mat;
	int		y;
	int		x;
	int		t;
	int		c;

	c = 10;
	t = 0;
	y = 0;
	mat = ft_split(str, ' ');
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			if (mat[y][x] == '-' || mat[y][x] == '+')
			{
				x++;
				c++;
			}
			if ((mat[y][x] < 48) || (mat[y][x] > 57))
			{
				free_mat(mat);
				return (1);
			}
			x++;
		}
		if (x > c)
			t++;
		else if (x == c && mat[y][c - 1] > 55 + (c - 10))
			t++;
		t += ft_dup(mat, y);
		y++;
	}
	free_mat(mat);
	return (t);
}
