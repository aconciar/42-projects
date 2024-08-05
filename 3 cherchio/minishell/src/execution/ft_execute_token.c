/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:58:52 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/19 17:01:18 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_there_is_redirect(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp && tmp->type != T_PIPE)
	{
		if (ft_is_red(tmp->type))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_execute_token(t_token *tmp, t_data **data, t_token *token)
{
	int		ret;
	pid_t	last_pid;

	last_pid = 0;
	ret = 0;
	if (ft_there_is_redirect(tmp) == 0)
		ret = ft_redirect(tmp, &data);
	if (ret == 0)
		last_pid = ft_execute(tmp, data, token);
	else
	{
		(*data)->exit_status = ret;
		(*data)->status_changed = true;
	}
	if ((*data)->infile < 0)
		(*data)->infile = 0;
	(*data)->here_doc = false;
	(*data)->redirect_out = false;
	(*data)->pipe_nbr--;
	return (last_pid);
}
