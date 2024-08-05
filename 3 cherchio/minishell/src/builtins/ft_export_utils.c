/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:03:46 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/21 15:39:58 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_var(char *var)
{
	int	i;
	int	len;

	len = ft_strlen(var) - 1;
	i = 0;
	if (ft_isalpha(var[0]) == 0 && var[0] != '_')
		return (ft_printf(2, "export: not valid in this context\n"));
	while (len > 0)
	{
		if (ft_isalnum(var[i]) == 0)
			if (var[i] != '_')
				return (ft_printf(2, "export: not valid in this context\n"));
		i++;
		len--;
	}
	if (ft_isalpha(var[i]) == 0 && var[i] != '_' && var[i] != '+')
		return (ft_printf(2, "export: not valid in this context\n"));
	return (0);
}

static int	ft_init_flag(char **var)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*var) - 1;
	if ((*var)[len] == '+')
	{
		tmp = ft_substr(*var, 0, len);
		free(*var);
		*var = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

int	ft_init_var(char **env, char **exp, char **var, t_data **exec)
{
	int	flag;

	flag = ft_init_flag(var);
	*env = ft_getenv(*exec, *var, (*exec)->envp);
	*exp = ft_getenv(*exec, *var, (*exec)->export);
	return (flag);
}
