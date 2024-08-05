/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:08:42 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/21 18:28:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_set_home(t_token *cmd, t_data **exec, char **home)
{
	if (cmd->next == NULL)
	{
		*home = ft_getenv(*exec, "HOME", (*exec)->envp);
		if (*home == NULL)
		{
			ft_set_exst_to_one(exec, "cd: HOME not set");
			return (1);
		}
	}
	else if (ft_is(cmd->next->value, "-") == 0)
	{
		*home = ft_getenv(*exec, "OLDPWD", (*exec)->envp);
		printf("%s\n", *home);
		if (*home == NULL)
		{
			ft_set_exst_to_one(exec, "cd: OLDPWD not set");
			return (1);
		}
	}
	else
		*home = ft_strdup(cmd->next->value);
	return (0);
}

void	ft_cd(t_data **exec, t_token *cmd)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;

	if (ft_list_size(cmd) > 2)			
		return (ft_set_exst_to_one(exec, "cd: too many arguments"));
	if (cmd->next)
		if (ft_iterate(cmd->next->value, ft_isspace) == 1)
			return (ft_set_exst_to_one(exec, "cd: too many arguments"));
	if (ft_set_home(cmd, exec, &home) != 0)
		return ;
	oldpwd = ft_getenv(*exec, "PWD", (*exec)->envp);
	ft_setenv(exec, "OLDPWD", oldpwd, 0);
	ft_free(oldpwd);
	if (chdir(home) == -1)
	{
		ft_free(home);
		ft_printf(2, "cd: %s: No such file or directory\n", cmd->next->value);
		ft_set_exst_to_one(exec, NULL);
		return ;
	}
	ft_free(home);
	pwd = getcwd(NULL, 0);
	ft_setenv(exec, "PWD", pwd, 0);
	ft_free(pwd);
}

static int	ft_set_home_process(char **mat, t_data **exec, char **home)
{
	if (mat[1] == NULL)
	{
		*home = ft_getenv(*exec, "HOME", (*exec)->envp);
		if (*home == NULL)
		{
			ft_set_exst_to_one(exec, "cd: HOME not set");
			return (1);
		}
	}
	else if (ft_is(mat[1], "-") == 0)
	{
		*home = ft_getenv(*exec, "OLDPWD", (*exec)->envp);
		printf("%s\n", *home);
		if (*home == NULL)
		{
			ft_set_exst_to_one(exec, "cd: OLDPWD not set");
			return (1);
		}
	}
	else
		*home = ft_strdup(mat[1]);
	return (0);
}

void	ft_cd_process(t_data **exec)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;

	if (ft_matlen((*exec)->cmd) > 2  || ft_iterate((*exec)->cmd[1], ft_isspace) == 1)
	{
		ft_set_exst_to_one(exec, "cd: too many arguments");
		return ;
	}
	if (ft_set_home_process((*exec)->cmd, exec, &home) != 0)
		return ;
	oldpwd = ft_getenv(*exec, "PWD", (*exec)->envp);
	ft_setenv(exec, "OLDPWD", oldpwd, 0);
	ft_free(oldpwd);
	if (chdir(home) == -1)
	{
		ft_free(home);
		ft_printf(2, "cd: %s: No such file or directory\n", (*exec)->cmd[1]);
		ft_set_exst_to_one(exec, NULL);
		return ;
	}
	ft_free(home);
	pwd = getcwd(NULL, 0);
	ft_setenv(exec, "PWD", pwd, 0);
	ft_free(pwd);
}
