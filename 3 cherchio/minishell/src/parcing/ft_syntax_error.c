/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:25:43 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/19 16:53:28 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_print_error(char *str)
{
	ft_printf(2, "minishell: syntax error near unexpected token `%s'\n", str);
	return (1);
}

int	ft_syntax_error(t_token *token)
{
	t_token			*tmp;

	tmp = token;
	if (tmp->type == T_PIPE)
		return (ft_print_error(tmp->value));
	while (tmp)
	{
		if (tmp->type == T_PIPE)
		{
			if (tmp->next == NULL || tmp->next->type == T_PIPE
				|| tmp->next->type == T_RED_IN || tmp->next->type == T_RED_HDOC)
				return (ft_print_error(tmp->value));
		}
		else if (ft_is_red(tmp->type) == 1)
		{
			if (tmp->next == NULL || tmp->next->type == T_PIPE
				|| ft_is_red(tmp->next->type) == 1)
				return (ft_print_error(tmp->value));
		}
		tmp = tmp->next;
	}
	return (0);
}
