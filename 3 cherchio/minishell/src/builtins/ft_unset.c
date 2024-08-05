/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:50 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/17 17:26:14 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_data **exec, t_token *cmd)
{
	t_token	*tmp;

	(*exec)->execute = false;
	tmp = cmd->next;
	while (tmp && (tmp->type == T_WORD || tmp->type == T_COMMAND))
	{
		if (ft_parse_var(tmp->value) == 1)
		{
			(*exec)->exit_status = 1;
			(*exec)->status_changed = true;
			return ;
		}
		ft_unsetenv(exec, tmp->value, 0);
		ft_unsetenv_export(exec, tmp->value, 0);
		tmp = tmp->next;
	}
}

void	ft_unset_process(t_data **exec)
{
	int		a;
	char	**mat;

	mat = (*exec)->cmd;
	a = 1;
	while (mat[a])
	{
		if (ft_parse_var(mat[a]) == 1)
		{
			(*exec)->exit_status = 1;
			(*exec)->status_changed = true;
			return ;
		}
		ft_unsetenv(exec, mat[a], 0);
		ft_unsetenv_export(exec, mat[a], 0);
		a++;
	}
}
