/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/09 15:53:58 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoinps(char *left_str, char *buff)
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

int	free_mat(char **mat, int i)
{
	int	y;

	y = 0;
	while (mat[y])
	{
		free(mat[y]);
		y++;
	}
	free(mat);
	return (i);
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

int	check_input(char *str, int y)
{
	char			**mat;
	long long int	n;

	mat = ft_split(str, ' ');
	if (!mat[0])
		return (free_mat(mat, 1));
	while (mat[y])
	{
		if (ft_strcmp(mat[y], "0") != 0)
		{
			n = ft_atoi(mat[y], 0);
			if (n > INT_MAX || n < INT_MIN || n == 0)
				return (free_mat(mat, 1));
			if (ft_dup(mat, y) == 1)
				return (free_mat(mat, 1));
		}
		else
		{
			n = ft_atoi(mat[y], 0);
			if (ft_dup(mat, y) == 1)
				return (free_mat(mat, 1));
		}
		y++;
	}
	return (free_mat(mat, 0));
}
