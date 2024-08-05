/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:45:19 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 17:35:07 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_here_doc(char *limiter, t_data ***data, int flag, int here_doc)
{
	char	*line;

	(**data)->here_doc = true;
	here_doc = open(".here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (here_doc == -1)
		return ;
	while (42)
	{
		signal(SIGINT, ft_signal_hc);
		signal(SIGQUIT, SIG_IGN);
		line = readline("heredoc>");
		if (!line || !ft_strcmp(line, limiter))
		{
			if (!line && g_exit_status == 0)
				ft_printf(1, "\n");
			break ;
		}
		if (flag == 8)
			line = ft_expand(line, **data, true);
		ft_printf(here_doc, "%s\n", line);
		ft_free(line);
	}
	ft_free(line);
	close(here_doc);
	(**data)->infile = open(".here_doc", O_RDONLY);
}

static int	ft_open(t_data ***data, char *filename, int flags)
{
	(**data)->outfile = open(filename, flags, 0777);
	if ((**data)->outfile == -1)
		return (ft_printf(2, "Error open file %s\n", filename));
	(**data)->redirect_out = true;
	return (0);
}

static int	ft_redirect_out(t_token *tmp, t_data ***data)
{
	if (tmp->type == T_RED_OUT)
		return (ft_open(data, tmp->next->value, O_CREAT | O_RDWR | O_TRUNC));
	else if (tmp->type == T_RED_APPEND)
		return (ft_open(data, tmp->next->value, O_CREAT | O_RDWR | O_APPEND));
	return (0);
}

int	ft_open_files(t_token *tmp, t_data ***data, int flag)
{
	while (tmp && tmp->type != T_PIPE)
	{
		if (tmp->type == T_RED_HDOC)
			ft_here_doc(tmp->next->value, data, (int)tmp->next->type, 0);
		if (tmp->type == T_RED_IN)
		{
			if ((**data)->infile >= 0)
				(**data)->infile = open(tmp->next->value, O_RDONLY, 0777);
			if ((**data)->infile == -1)
			{
				if (flag == 0)
					return (ft_printf(2, "Error open file %s\n",
							tmp->next->value), 1);
				else
					(**data)->infile = -1;
			}
		}
		else
			if (ft_redirect_out(tmp, data) != 0)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}
