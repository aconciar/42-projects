/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:26:08 by andrea            #+#    #+#             */
/*   Updated: 2024/02/12 19:23:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	**path;
	char	*path_ok;

	cmd = ft_split(argv, ' ');
	path = ft_path(envp);
	path_ok = ft_find_path(path, cmd[0]);
	if (!path_ok)
		exit (5);
	if (execve(path_ok, cmd, envp) == -1)
		exit (6);
}
