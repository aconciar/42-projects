/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:26:08 by andrea            #+#    #+#             */
/*   Updated: 2024/03/28 18:59:57 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (7);
}

char	*ft_find_path(char **path, char *argv)
{
	int	i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], argv);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
		i++;
	}
	return (NULL);
}

char	**ft_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (ft_split((envp[i] + 5), ':'));
		i++;
	}
	return (NULL);
}

int	is_path(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/' )
			return (1);
		i++;
	}
	return (0);
}

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	**path;
	char	*path_ok;

	cmd = ft_split(argv, ' ');
	path = ft_path(envp);
	// if (is_path(cmd[0]) == 1)
	// 	path_ok = ft_strdup(cmd[0]);
	// else
		path_ok = ft_find_path(path, cmd[0]);
	// if (!path_ok)
	// 	ft_error("Error execve1\n");
	if (execve(path_ok, cmd, envp) == -1)
		ft_error("Error execve\n");
}
