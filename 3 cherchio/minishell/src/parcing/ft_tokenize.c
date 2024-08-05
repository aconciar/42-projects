/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:38:32 by fdonati           #+#    #+#             */
/*   Updated: 2024/06/20 18:20:03 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_token_redir(int end, char *tmp, int start, t_token **new)
{
	char	*str;

	str = ft_substr(tmp, start, end - start);
	if (str[0] != '\0')
		ft_list_addback(new, ft_create_node(T_COMMAND, str));
	if (tmp[end] == '<' && tmp[end + 1] == tmp[end])
	{
		ft_list_addback(new, ft_create_node(T_RED_HDOC, "<<"));
		end++;
	}
	else if (tmp[end] != '>' && tmp[end] != '<')
		ft_list_addback(new, ft_create_node(T_COMMAND, str));
	else if (tmp[end] == '>' && tmp[end + 1] == tmp[end])
	{
		ft_list_addback(new, ft_create_node(T_RED_APPEND, ">>"));
		end++;
	}
	else if (tmp[end] == '<')
		ft_list_addback(new, ft_create_node(T_RED_IN, "<"));
	else if (tmp[end] == '>')
		ft_list_addback(new, ft_create_node(T_RED_OUT, ">"));
	free(str);
	return (end + 1);
}

static char	*ft_cutstring(t_token **new, char *tmp, int *i, char **envp)
{
	int		start;
	int		end;
	char	*s;

	s = NULL;
	start = *i;
	while (tmp[*i] && tmp[*i] != '|' && tmp[*i] != '<' && tmp[*i] != '>')
		(*i)++;
	end = *i;
	if (tmp[*i] == '|')
	{
		s = ft_substr(tmp, start, end - start);
		if (s[0] != '\0')
			ft_list_addback(new, ft_create_node(ft_find_token(s, envp, 0), s));
		ft_list_addback(new, ft_create_node(T_PIPE, "|"));
		(*i)++;
	}
	else if (tmp[*i] == '<' || tmp[*i] == '>')
		(*i) = ft_token_redir(end, tmp, start, new);
	else
	{
		s = ft_substr(tmp, start, end - start);
		ft_list_addback(new, ft_create_node(ft_find_token(s, envp, 0), s));
	}
	return (s);
}

static void	ft_word(t_token **new, char *tmp, int i, char **envp)
{
	char	*str;

	str = NULL;
	while (tmp[i])
	{
		str = ft_cutstring(new, tmp, &i, envp);
		ft_free(str);
	}
}

static void	ft_create_token(t_token **token, t_token *cmds, t_data *data)
{
	t_token_type	type;

	while (cmds)
	{
		type = ft_find_token(cmds->value, data->envp, cmds->type);
		if (cmds->value == NULL)
			ft_list_addback(token, ft_create_node(T_WORD, NULL));
		else if (type == T_WORD)
			ft_word(token, cmds->value, 0, data->envp);
		else
			ft_list_addback(token, ft_create_node(type, cmds->value));
		if (type == T_RED_HDOC)
		{
			cmds = cmds->next;
			if (cmds->type == T_SEP)
				cmds = cmds->next;
			if (cmds == NULL)
				break ;
			if (cmds->type == T_QUOTES)
				ft_list_addback(token, ft_create_node(T_LIM_QTS, cmds->value));
			else
				ft_list_addback(token, ft_create_node(T_LIM, cmds->value));
		}
		cmds = cmds->next;
	}
}

t_token	*ft_tokenize(char *line, t_data *data)
{
	char	*trim;
	t_token	*cmds;
	t_token	*tmp;
	t_token	*token;

	tmp = NULL;
	trim = ft_strtrim(line, " \t\n\v\f\r");
	if (trim[0] == '\0' || ft_open_quotes(trim) == 1)
		return (free(trim), NULL);
	cmds = ft_split_cmd(trim, data);
	ft_free(trim);
	ft_create_token(&tmp, cmds, data);
	ft_free_list(cmds);
	token = ft_parsing(tmp);
	ft_free_list(tmp);
	return (token);
}
