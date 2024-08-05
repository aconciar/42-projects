/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:41:23 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/19 21:13:07 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

static char	*ft_limiter(t_token **tok, int *t, t_token_type *type, char *tmp)
{
	tmp = ft_strdup((*tok)->value);
	*type = (*tok)->type;
	*tok = (*tok)->next;
	*t = 0;
	return (tmp);
}

static char	*ft_operator(t_token **tok, int *t, t_token_type *tp, char *tmp)
{
	tmp = ft_strdup((*tok)->value);
	*tp = (*tok)->type;
	*tok = (*tok)->next;
	if (*tok && (*tok)->type == T_SEP)
		*tok = (*tok)->next;
	if (*tok != NULL)
	{
		if ((*tok)->type == T_PIPE)
			return (tmp);
	}
	if (*tp != T_PIPE)
		*t = 1;
	return (tmp);
}

static char	*ft_create_block(t_token **token, t_token_type *type, char *tmp)
{
	if ((*token)->type == T_SEP)
	{
		*type = T_SEP;
		*token = (*token)->next;
		return (NULL);
	}
	tmp = ft_strdup((*token)->value);
	*type = (*token)->type;
	*token = (*token)->next;
	while (*token && (*token)->type != T_PIPE && ft_is_red((*token)->type) == 0)
	{
		if ((*token)->type == T_SEP)
			break ;
		tmp = ft_strfjoin(tmp, (*token)->value);
		*token = (*token)->next;
	}
	if (*type == T_WORD && tmp[0] != '\0')
		*type = T_COMMAND;
	return (tmp);
}

t_token	*ft_parsing(t_token *tok)
{
	t_token			*new;
	t_token_type	type;
	char			*tmp;
	int				t;

	t = 0;
	new = NULL;
	type = T_WORD;
	while (tok)
	{
		tmp = NULL;
		if (tok->type == T_LIM || tok->type == T_LIM_QTS)
			tmp = ft_limiter(&tok, &t, &type, tmp);
		else if (t == 1)
			tmp = ft_fd(&tok, &t, &type, tmp);
		else if (tok && (ft_is_red(tok->type) == 1 || tok->type == T_PIPE))
			tmp = ft_operator(&tok, &t, &type, tmp);
		else
			tmp = ft_create_block(&tok, &type, tmp);
		if (type != T_SEP)
			ft_list_addback(&new, ft_create_node(type, tmp));
		ft_free(tmp);
	}
	return (new);
}
