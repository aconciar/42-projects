/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:36:13 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/21 17:59:20 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_init_exec(t_data **exc, t_token *token)
{
	(*exc)->cmd = ft_create_cmd(token);
	(*exc)->type = token->type;
	if ((*exc)->type != T_BUILTIN)
	{
		(*exc)->path = ft_path((*exc)->envp);
		if ((*exc)->path == NULL)
			return (ft_printf(2, "Error: path not found\n"));
		if (is_path(token->value) == 1)
		{
			(*exc)->path_ok = ft_strdup(token->value);
			if (access((*exc)->path_ok, F_OK) != 0)
			{
				ft_free((*exc)->path_ok);
				ft_printf(2, "%s :No such file or directory\n", (*exc)->cmd[0]);
				return (1);
			}
		}
		else
			(*exc)->path_ok = ft_find_path((*exc)->path, (*exc)->cmd[0]);
		if ((*exc)->path_ok == NULL && ((*exc)->cmd[0]) != NULL)
			return (ft_printf(2, "%s : command not found\n", (*exc)->cmd[0]));
		else if ((*exc)->path_ok == NULL && ((*exc)->cmd[0]) == NULL)
			return (ft_printf(2, "'' : command not found\n"));
	}
	return (0);
}

pid_t	ft_execute(t_token *tmp, t_data **exec, t_token *token)
{
	pid_t	pid;

	if (ft_init_exec(exec, tmp) != 0)
	{
		(*exec)->exit_status = 127;
		if ((*exec)->type != T_BUILTIN)
			ft_free_matrix((*exec)->path);
		ft_free_matrix((*exec)->cmd);
		return (0);
	}
	if ((*exec)->pipe_nbr > 0)
		pid = ft_exec_pipe(exec, token);
	else
		pid = ft_exec_pipezero(exec, &token);
	if ((*exec)->type != T_BUILTIN)
	{
		ft_free_matrix((*exec)->path);
		ft_free((*exec)->path_ok);
	}
	ft_free_matrix((*exec)->cmd);
	if ((*exec)->status_changed == true)
		return ((*exec)->exit_status);
	return (pid);
}
