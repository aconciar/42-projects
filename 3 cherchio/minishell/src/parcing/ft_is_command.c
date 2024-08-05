/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:41:40 by andrea            #+#    #+#             */
/*   Updated: 2024/06/17 18:36:10 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_find_path_cmd(char **path, char *argv)
{
	int	i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strfjoin(path[i], "/");
		path[i] = ft_strfjoin(path[i], argv);
		if (access(path[i], X_OK) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**ft_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			path = ft_split((envp[i] + 5), ':');
			return (path);
		}
		i++;
	}
	return (NULL);
}

int	ft_is_command(char *cmd, char **envp)
{
	char	**path;
	int		i;

	path = ft_path(envp);
	if (!path)
	{
		ft_free_matrix(path);
		return (1);
	}
	i = ft_find_path_cmd(path, cmd);
	ft_free_matrix(path);
	return (i);
}
