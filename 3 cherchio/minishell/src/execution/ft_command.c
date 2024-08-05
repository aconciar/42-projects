/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:29:51 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/19 17:03:04 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_pipe_nbr(t_token *token)
{
	int	pipe_nbr;

	pipe_nbr = 0;
	while (token)
	{
		if (token->type == T_PIPE)
			pipe_nbr++;
		token = token->next;
	}
	return (pipe_nbr);
}

static void	ft_data_init(t_token *token, t_data ***data)
{
	(**data)->outfile = 0;
	(**data)->infile = 0;
	(**data)->pipe_nbr = ft_pipe_nbr(token);
	(**data)->cmd_nbr = ft_pipe_nbr(token) + 1;
	(**data)->original_stdin = dup(STDIN_FILENO);
	(**data)->original_stdout = dup(STDOUT_FILENO);
	(**data)->redirect_out = false;
	(**data)->here_doc = false;
}

static int	ft_wait_last_pid(pid_t last_pid, t_data **data)
{
	int	ret;
	int	i;

	i = (*data)->cmd_nbr;
	ret = 0;
	while (i > 0)
	{
		if (wait(&ret) == last_pid)
		{
			if (WIFEXITED(ret))
				ret = WEXITSTATUS(ret);
		}
		else if (last_pid == 0)
			ret = ((*data)->exit_status);
		i--;
	}
	return (ret);
}

static void	ft_skip_block(t_token **tmp)
{
	while (*tmp)
	{
		if ((*tmp)->type == T_PIPE)
		{
			*tmp = (*tmp)->next;
			break ;
		}
		*tmp = (*tmp)->next;
	}
}

int	ft_command(t_token *token, t_data **data)
{
	pid_t	last_pid;
	t_token	*tmp;
	int		ret;

	tmp = token;
	ft_data_init(tmp, &data);
	if (ft_syntax_error(tmp) == 1)
		return (2);
	while (tmp && (*data)->pipe_nbr >= 0)
	{
		if ((*data)->pipe_nbr == 0)
			last_pid = ft_execute_token(tmp, data, token);
		else
			ft_execute_token(tmp, data, token);
		ft_skip_block(&tmp);
	}
	ret = ft_wait_last_pid(last_pid, data);
	ft_original_std(data);
	return (ret);
}
