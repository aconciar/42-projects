/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:40:08 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 16:29:08 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_find_path(char **path, char *argv)
{
	int		i;
	char	*tmp;

	i = 0;
	if (argv == NULL)
		return (NULL);
	while (path[i])
	{
		path[i] = ft_strfjoin(path[i], "/");
		path[i] = ft_strfjoin(path[i], argv);
		if (access(path[i], F_OK) == 0)
		{
			tmp = ft_strdup(path[i]);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

int	is_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
