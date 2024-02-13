/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_addfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:47:13 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/12 18:01:18 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_addfront(t_stack **list, t_stack *new)
{
	if (!list || !new)
		return ;
	if (!(*list))
	{
		*list = new;
		(*list)->prev = NULL;
		(*list)->next = NULL;
		return ;
	}
	(*list)->prev = new;
	new->prev = NULL;
	new->next = (*list);
	if ((*list)->prev != NULL)
		(*list)->prev = new;
	*list = new;
}
