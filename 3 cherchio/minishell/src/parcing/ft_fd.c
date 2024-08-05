/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:12:24 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/10 21:44:56 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_fd(t_token **token, int *t, t_token_type *type, char *tmp)
{
	tmp = ft_strdup((*token)->value);
	if (ft_is_red((*token)->type) == 1)
	{
		*type = (*token)->type;
		*token = (*token)->next;
		*t = 0;
		return (tmp);
	}
	*type = T_FD;
	*token = (*token)->next;
	*t = 0;
	return (tmp);
}
