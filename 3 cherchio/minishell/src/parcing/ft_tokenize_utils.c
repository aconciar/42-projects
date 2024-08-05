/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:53:37 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/19 18:30:49 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin(char *line)
{
	if (ft_is(line, "exit") == 0)
		return (0);
	if (ft_is(line, "echo") == 0)
		return (0);
	if (ft_is(line, "cd") == 0)
		return (0);
	if (ft_is(line, "env") == 0)
		return (0);
	if (ft_is(line, "unset") == 0)
		return (0);
	if (ft_is(line, "pwd") == 0)
		return (0);
	if (ft_is(line, "export") == 0)
		return (0);
	return (1);
}

t_token_type	ft_find_token(char *value, char **envp, t_token_type type)
{
	if (ft_is_builtin(value) == 0)
		return (T_BUILTIN);
	else if (ft_strcmp(value, ">") == 0)
		return (T_RED_OUT);
	else if (ft_strcmp(value, ">>") == 0)
		return (T_RED_APPEND);
	else if (ft_strcmp(value, "<") == 0)
		return (T_RED_IN);
	else if (ft_strcmp(value, "<<") == 0)
		return (T_RED_HDOC);
	else if (ft_strcmp(value, "|") == 0 && type != T_QUOTES)
		return (T_PIPE);
	else if (ft_is_command(value, envp) == 0)
		return (T_COMMAND);
	else if (type == T_QUOTES)
		return (T_QUOTES);
	else if (type == T_SEP)
		return (T_SEP);
	else
		return (T_WORD);
}
