/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:13:37 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/02 21:21:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_push(t_stack *stack, int chunk1, int chunk2)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->chunk == chunk1 || stack->chunk == chunk2)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, int c, int m)
{
	int	i;

	i = find_push(*stack_a, c, m);
	while (i > 0)
	{
		if (i > ft_list_size(*stack_a) / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
		i--;
	}
	if ((*stack_a)->chunk == m)
		pb(stack_b, stack_a, 1);
	else if ((*stack_a)->chunk == c)
	{
		pb(stack_b, stack_a, 1);
		if (ft_list_size(*stack_b) > 1)
			rb(stack_b, 1);
	}
}
