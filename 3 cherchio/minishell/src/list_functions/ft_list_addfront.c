/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_addfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:47:13 by ucolla            #+#    #+#             */
/*   Updated: 2024/04/05 16:33:49 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_list_addfront(t_token **list, t_token *new)
{
	if (!list || !new)
		return ;
	if (!(*list))
	{
		*list = new;
		(*list)->next = NULL;
		return ;
	}
	new->next = (*list);
	*list = new;
}
