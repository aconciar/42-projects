/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:41:57 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 19:13:09 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_exit_status_process(char **mat, t_data **data, int i)
{
	int		a;

	a = 1;
	while (mat[a][i])
	{
		if (ft_isdigit(mat[a][i]) == 0 && mat[a][i] != '-'
			&& mat[a][i] != '+')
		{
			ft_printf(2, "minishell:exit: %s: numeric argument required\n",
				mat[a]);
			(*data)->exit = true;
			(*data)->exit_status = 2;
			return ;
		}
		i++;
	}
	(*data)->exit_status = ft_atoi(mat[a]);
	(*data)->exit = true;
	if (ft_matlen((*data)->cmd) > 2)
	{
		(*data)->exit = false;
		(*data)->exit_status = 1;
		ft_printf(2, "minishell: exit: too many arguments\n");
	}
}

int	ft_exit_process(t_data **data)
{
	if (ft_matlen((*data)->cmd) == 1)
		(*data)->exit = true;
	else
		ft_exit_status_process((*data)->cmd, data, 0);
	if ((*data)->exit == true)
		return (1);
	return (0);
}

static void	ft_exit_status(t_token *cmd, t_data **data, int i)
{
	t_token	*t;

	t = cmd->next;
	while (t->value[i])
	{
		if (ft_isdigit(t->value[i]) == 0 && t->value[i] != '-'
			&& t->value[i] != '+')
		{
			ft_printf(2, "minishell:exit: %s: numeric argument required\n",
				t->value);
			(*data)->exit = true;
			(*data)->exit_status = 2;
			return ;
		}
		i++;
	}
	(*data)->exit_status = (unsigned char)ft_atoi(t->value);
	(*data)->exit = true;
	if (ft_list_size(cmd) > 2)
	{
		(*data)->exit = false;
		(*data)->exit_status = 1;
		ft_printf(2, "minishell: exit: too many arguments\n");
	}
}

int	ft_exit(t_token *cmd, t_data **data)
{
	ft_printf(1, "exit\n");
	if (ft_list_size(cmd) == 1)
		(*data)->exit = true;
	else
		ft_exit_status(cmd, data, 0);
	if ((*data)->exit == true)
		return (1);
	return (0);
}
