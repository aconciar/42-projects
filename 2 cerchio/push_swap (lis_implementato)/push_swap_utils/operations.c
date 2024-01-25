/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:15:21 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/12 16:38:36 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack, t_stack **node)
{
	t_stack	*tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	ft_printf("pa\n");
}

void	pb(t_stack **stack, t_stack **node)
{
	t_stack	*tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	ft_printf("pb\n");
}

