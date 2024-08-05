/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:30:31 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/19 19:16:24 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_original_std(t_data **data)
{
	if ((*data)->here_doc == true)
		unlink(".here_doc");
	close((*data)->outfile);
	close((*data)->infile);
	dup2((*data)->original_stdin, STDIN_FILENO);
	dup2((*data)->original_stdout, STDOUT_FILENO);
}

int	ft_is_red(int type)
{
	if (type == T_RED_IN || type == T_RED_OUT
		|| type == T_RED_APPEND || type == T_RED_HDOC)
		return (1);
	return (0);
}

int	ft_redirect(t_token *token, t_data ***data)
{
	t_token	*tmp;
	int		flag;

	flag = 0;
	tmp = token;
	while (tmp && tmp->type != T_PIPE)
	{
		if (tmp->type == T_RED_HDOC)
			flag = 1;
		tmp = tmp->next;
	}
	tmp = token;
	if (ft_open_files(tmp, data, flag) != 0)
		return (1);
	if (flag == 1 && (**data)->infile < 0)
		if ((**data)->infile == -1)
			return (ft_printf(2, "Error open file\n"), 1);
	dup2((**data)->infile, STDIN_FILENO);
	return (0);
}
