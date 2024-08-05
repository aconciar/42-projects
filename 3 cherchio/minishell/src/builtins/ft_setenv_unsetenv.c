/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_unsetenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:27:28 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/21 18:05:09 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv_export(t_data **data, char *env_var, int f)
{
	int		i;
	int		j;
	char	**new;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ft_getenv(*data, env_var, (*data)->export);
	if (tmp == NULL)
		f = 1;
	ft_free(tmp);
	new = (char **)malloc(sizeof(char *) * (ft_matlen((*data)->export) + f));
	while ((*data)->export[i] != NULL)
	{
		if (ft_strncmp((*data)->export[i], env_var, ft_strlen(env_var)) != 0)
		{
			new[j] = ft_strdup((*data)->export[i]);
			j++;
		}
		i++;
	}
	new[j] = NULL;
	ft_free_matrix((*data)->export);
	(*data)->export = NULL;
	(*data)->export = new;
}

void	ft_unsetenv(t_data **data, char *env_var, int f)
{
	int		i;
	int		j;
	char	**new;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ft_getenv(*data, env_var, (*data)->envp);
	if (tmp == NULL)
		f = 1;
	ft_free(tmp);
	new = (char **)malloc(sizeof(char *) * (ft_matlen((*data)->envp) + f));
	while ((*data)->envp[i] != NULL)
	{
		if (ft_strncmp((*data)->envp[i], env_var, ft_strlen(env_var)) != 0)
		{
			new[j] = ft_strdup((*data)->envp[i]);
			j++;
		}
		i++;
	}
	new[j] = NULL;
	ft_free_matrix((*data)->envp);
	(*data)->envp = NULL;
	(*data)->envp = new;
}

void	ft_setenv_export(t_data **data, char *env_var, char *value, int flag)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*data)->export[i] != NULL)
	{
		if (ft_strncmp((*data)->export[i], env_var, ft_strlen(env_var)) == 0)
		{
			tmp = ft_strjoin(env_var, "=");
			if (flag == 0)
			{
				ft_free((*data)->export[i]);
				(*data)->export[i] = ft_strjoin(tmp, value + 1);
			}
			else
				(*data)->export[i] = ft_strfjoin((*data)->export[i], value + 1);
			ft_free(tmp);
			return ;
		}
		i++;
	}
}

void	ft_setenv(t_data **data, char *env_var, char *value, int flag)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*data)->envp[i] != NULL)
	{
		if (ft_strncmp((*data)->envp[i], env_var, ft_strlen(env_var)) == 0)
		{
			tmp = ft_strjoin(env_var, "=");
			if (flag == 0)
			{
				ft_free((*data)->envp[i]);
				(*data)->envp[i] = ft_strjoin(tmp, value + 1);
			}
			else
				(*data)->envp[i] = ft_strfjoin((*data)->envp[i], value + 1);
			ft_free(tmp);
			return ;
		}
		i++;
	}
}
