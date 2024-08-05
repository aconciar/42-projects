/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:02:53 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/19 18:42:13 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

static void	ft_print_export(t_data **exc, int i)
{
	int		j;
	char	*var;
	char	*val;

	if (ft_matlen((*exc)->cmd) != 1)
		return ;
	while ((*exc)->export[i])
	{
		j = 0;
		while ((*exc)->export[i][j] && (*exc)->export[i][j] != '=')
			j++;
		var = ft_substr((*exc)->export[i], 0, j);
		if (j == (int)ft_strlen((*exc)->export[i]))
			ft_printf(1, "declare -x %s\n", var);
		else
		{
			j++;
			val = ft_substr((*exc)->export[i], j, ft_strlen((*exc)->export[i]));
			ft_printf(1, "declare -x %s=\"%s\"\n", var, val);
			ft_free(val);
		}
		ft_free(var);
		i++;
	}
}

static void	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_printf(1, "%s\n", pwd);
	ft_free(pwd);
}

static void	ft_env(char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		ft_printf(1, "%s\n", environ[i]);
		i++;
	}
}

int	ft_builtin(t_data **exec)
{
	if (ft_is((*exec)->cmd[0], "echo") == 0)
		ft_echo((*exec)->cmd);
	else if (ft_is((*exec)->cmd[0], "env") == 0)
		ft_env((*exec)->envp);
	else if (ft_is((*exec)->cmd[0], "pwd") == 0)
		ft_pwd();
	else if (ft_is((*exec)->cmd[0], "export") == 0 && (*exec)->cmd[1] == NULL)
		ft_print_export(exec, 0);
	else if (ft_is((*exec)->cmd[0], "cd") == 0)
		ft_cd_process(exec);
	else if (ft_is((*exec)->cmd[0], "export") == 0)
		ft_set_export_process(exec, 0, NULL, 1);
	else if (ft_is((*exec)->cmd[0], "unset") == 0)
		ft_unset_process(exec);
	else if (ft_is((*exec)->cmd[0], "exit") == 0)
	{
		if (ft_exit_process(exec) != 0)
			return ((*exec)->exit_status);
	}
	return (0);
}
