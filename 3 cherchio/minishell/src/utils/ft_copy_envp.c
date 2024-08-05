/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:35:32 by fdonati           #+#    #+#             */
/*   Updated: 2024/06/19 18:47:10 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	swap_strings(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_sort_env(char **environ)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_matlen(environ);
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (ft_strcmp(environ[j], environ[j + 1]) > 0)
				swap_strings(&environ[j], &environ[j + 1]);
			j++;
		}
		i++;
	}
}

void	ft_free_envp(char ***envp)
{
	int	i;

	i = 0;
	if (!*envp)
		return ;
	while ((*envp)[i])
	{
		ft_free((*envp)[i]);
		i++;
	}
	free(*envp);
	*envp = NULL;
}

char	**ft_copy_envp(char **envp)
{
	char	**new;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	new = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		new[i] = ft_strdup(envp[i]);
		if (!new[i])
		{
			ft_free_envp(&new);
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}
