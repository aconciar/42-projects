/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_no_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:24:24 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/21 18:14:38 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtins_no_process(t_token *token, t_data **data)
{
	if (ft_list_find_node(token, T_PIPE) == 0)
		return (0);
	if (ft_is(token->value, "cd") == 0)
	{
		ft_cd(data, token);
		(*data)->execute = false;
	}
	else if (ft_is(token->value, "export") == 0)
		ft_set_export(data, token, 0, NULL);
	else if (ft_is(token->value, "unset") == 0)
		ft_unset(data, token);
	else if (ft_is(token->value, "exit") == 0)
	{
		(*data)->execute = false;
		if (ft_exit(token, data) != 0)
			return ((*data)->exit);
	}
	return (0);
}
