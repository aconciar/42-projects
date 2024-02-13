/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/02 21:22:13 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smallest_on_top(t_stack **stack)
{
	while ((*stack)->index != find_smallest(*stack))
	{
		if (find_eff(*stack, find_smallest(*stack))
			> (ft_list_size(*stack) / 2))
			rra(stack, 1);
		else
			ra(stack, 1);
	}
}

int	check_push(t_stack *stack, int c, int m)
{
	while (stack)
	{
		if (stack->chunk == c || stack->chunk == m)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_eff(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_list_size(*stack_a) > 3 && check_push(*stack_a, 1, 4) == 0)
		push_a_to_b(stack_a, stack_b, 1, 4);
	while (ft_list_size(*stack_a) > 3 && check_push(*stack_a, 2, 3) == 0)
		push_a_to_b(stack_a, stack_b, 2, 3);
	three_numbers_a(stack_a);
	while ((*stack_b)->next)
		push_b_to_a(stack_b, stack_a);
	push_b_to_a(stack_b, stack_a);
	ft_smallest_on_top(stack_a);
}
