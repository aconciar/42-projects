/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:57:09 by ucolla            #+#    #+#             */
/*   Updated: 2023/12/20 17:26:51 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack)
{
	t_list	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	ft_printf("sa\n");
}

void	sb(t_list **stack)
{
	t_list	*node;

	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}