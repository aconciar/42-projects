/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:17:47 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/20 17:27:00 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack)
{
	t_list	*value;

	value = *stack;
	*stack = (*stack)->next;
	value->next = NULL;
	ft_lstadd_back(stack, value);
	ft_printf("ra\n");
}

void	rb(t_list **stack)
{
	t_list	*value;

	value = *stack;
	*stack = (*stack)->next;
	value->next = NULL;
	ft_lstadd_back(stack, value);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}