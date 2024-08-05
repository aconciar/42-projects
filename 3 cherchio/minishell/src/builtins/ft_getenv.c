/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:11:13 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 18:30:51 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_expand_exit_status(t_data *data, char *env_var)
{
	char	*tmp;
	char	*value;
	int		i;

	i = 1;
	tmp = ft_itoa(data->exit_status);
	if (env_var[0] == '\0')
		value = ft_strjoin(tmp, env_var + 1);
	else
		value = ft_strdup(tmp);
	ft_free(tmp);
	tmp = ft_strdup(env_var + i);
	value = ft_strfjoin(value, tmp);
	ft_free(tmp);
	return (value);
}

char	*ft_getenv(t_data *data, char *env_var, char **envp)
{
	int		i;
	char	*value;

	i = 0;
	if (env_var[0] == '\0')
	{
		value = ft_strdup("$");
		return (value);
	}
	else if (env_var[0] == '?')
		return (ft_expand_exit_status(data, env_var));
	while (envp[i])
	{
		if (ft_strncmp(envp[i], env_var, ft_strlen(env_var)) == 0)
		{
			if (envp[i][ft_strlen(env_var)] == '\0')
				value = ft_strdup("");
			else
				value = ft_strdup(envp[i] + ft_strlen(env_var) + 1);
			return (value);
		}
		i++;
	}
	return (NULL);
}
