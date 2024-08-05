/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:09:50 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/21 15:40:09 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_setting(t_data **exec, char *var, char *new_value, t_token **tmp)
{
	char	*env;
	char	*exp;
	int 	flag;

	flag = ft_init_var(&env, &exp, &var, exec);
	if (exp == NULL)
	{
		(*exec)->export = ft_matjoin((*exec)->export, (*tmp)->value);
		if (new_value[0] != '\0')
			(*exec)->envp = ft_matjoin((*exec)->envp, (*tmp)->value);
	}
	else if (env == NULL)
	{
		ft_setenv_export(exec, var, new_value, flag);
		if (new_value[0] != '\0')
			(*exec)->envp = ft_matjoin((*exec)->envp, (*tmp)->value);
	}
	else if (new_value[0] != '\0')
	{
		ft_setenv(exec, var, new_value, flag);
		ft_setenv_export(exec, var, new_value, flag);
	}
	ft_free_both(env, exp);
	*tmp = (*tmp)->next;
	free(var);
}

void	ft_set_export(t_data **exec, t_token *cmd, int i, char *var)
{
	char	*new_value;
	t_token	*tmp;

	tmp = cmd->next;
	while (tmp && (tmp->type == T_WORD || tmp->type == T_COMMAND
			|| tmp->type == T_QUOTES))
	{
		i = 0;
		(*exec)->execute = false;
		if (tmp->type == T_RED_OUT || tmp->type == T_RED_APPEND)
			return ;
		while (tmp->value[i] && tmp->value[i] != '=')
			i++;
		var = ft_substr(tmp->value, 0, i);
		new_value = ft_substr(tmp->value, i, ft_strlen(tmp->value));
		if (ft_parse_var(var) != 0)
		{
			ft_free_both(var, new_value);
			ft_set_exst_to_one(exec, NULL);
			return ;
		}
		ft_setting(exec, var, new_value, &tmp);
		ft_sort_env((*exec)->export);
		ft_free(new_value);
	}
}

static void	ft_setting_process(t_data **exec, char *var, char *new_value, int a)
{
	char	*env;
	char	*exp;
	int 	flag;

	flag = ft_init_var(&env, &exp, &var, exec);
	if (exp == NULL)
	{
		(*exec)->export = ft_matjoin((*exec)->export, (*exec)->cmd[a]);
		if (new_value[0] != '\0')
			(*exec)->envp = ft_matjoin((*exec)->envp, (*exec)->cmd[a]);
	}
	else if (env == NULL)
	{
		ft_setenv_export(exec, var, new_value, flag);
		if (new_value[0] != '\0')
			(*exec)->envp = ft_matjoin((*exec)->envp, (*exec)->cmd[a]);
	}
	else if (new_value[0] != '\0')
	{
		ft_setenv(exec, var, new_value, flag);
		ft_setenv_export(exec, var, new_value, flag);
	}
	ft_free_both(exp, env);
	ft_sort_env((*exec)->export);
	free(var);
}

void	ft_set_export_process(t_data **exec, int i, char *var, int a)
{
	char	*new_value;
	char	**mat;

	mat = (*exec)->cmd;
	while (mat[a])
	{
		i = 0;
		while (mat[a][i] && mat[a][i] != '=')
			i++;
		var = ft_substr(mat[a], 0, i);
		i++;
		new_value = ft_substr(mat[a], i, ft_strlen(mat[a]));
		if (ft_parse_var(var) == 1)
		{
			ft_free_both(var, new_value);
			ft_set_exst_to_one(exec, NULL);
			return ;
		}
		ft_setting_process(exec, var, new_value, a);
		ft_free(new_value);
		a++;
	}
}
