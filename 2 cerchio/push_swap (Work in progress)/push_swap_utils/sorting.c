/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/25 16:15:32 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_smallest_on_top(t_stack **stack)
{
	while((*stack)->index != find_smallest(*stack))
	{
		if (find_eff(*stack, find_smallest(*stack)) > (ft_list_size(*stack) / 2))
			rra(stack);
		else
			ra(stack);
	}
}


int ft_check_push(t_stack *stack)
{
	while (stack)
	{
		if (stack->push == 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	find_eff(t_stack *stack, int index)
{
	int i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return(-1);
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->push == 0)
		pb(stack_b, stack_a);
	else
	{
		while ((*stack_a)->push != 0)
			ra(stack_a);
		pb(stack_b, stack_a);
	}
	if ((*stack_a)->push == 0)
		pb(stack_b, stack_a);
	else
	{
		while ((*stack_a)->push == 1)
			ra(stack_a);
		pb(stack_b, stack_a);
	}
	while (ft_check_push(*stack_a) == 1)
		push_a_to_b(stack_a, stack_b);
	ft_smallest_on_top(stack_a);
	while ((*stack_b)->next)
		push_b_to_a(stack_b, stack_a);
	push_b_to_a(stack_b, stack_a);
	ft_smallest_on_top(stack_a);
}
