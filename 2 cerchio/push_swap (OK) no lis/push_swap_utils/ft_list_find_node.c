/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:49:12 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/23 16:30:25 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_list_find_node(t_stack *list, int value)
{
	while (list)
	{
		if (list->value == value)
		{
			// ft_printf("list->value : %d\n", list->value);
			return (list);
		}
		list = list->next;
	}
	return (NULL);
}
