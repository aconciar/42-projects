/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:15:21 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/06 17:40:35 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack, t_stack **node, int i)
{
	t_stack	*tmp_node;

	if (!(*node))
		return ;
	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	if (i == 1)
		ft_printf("pa\n");
}

void	pb(t_stack **stack, t_stack **node, int i)
{
	t_stack	*tmp_node;

	if (!(*node))
		return ;
	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	if (i == 1)
		ft_printf("pb\n");
}
