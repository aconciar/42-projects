/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:12:43 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 16:28:34 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_size(t_token *tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp->type != T_PIPE)
	{
		if (ft_is_red(tmp->type) == 0 && tmp->type != T_FD
			&& tmp->type != T_LIM && tmp->type != T_LIM_QTS
				&& tmp->value[0] != '\0')
			i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**ft_create_cmd(t_token *token)
{
	t_token	*tmp;
	char	**cmd;
	int		i;

	tmp = token;
	cmd = malloc(sizeof(char *) * (ft_count_size(tmp) + 1));
	if (cmd == NULL)
		return (NULL);
	i = 0;
	tmp = token;
	while (tmp && tmp->type != T_PIPE)
	{
		if (ft_is_red(tmp->type) == 0 && tmp->type != T_FD
			&& tmp->type != T_LIM && tmp->type != T_LIM_QTS
				&& tmp->value[0] != '\0')
		{
			cmd[i] = ft_strdup(tmp->value);
			i++;
		}
		tmp = tmp->next;
	}
	cmd[i] = NULL;
	return (cmd);
}
