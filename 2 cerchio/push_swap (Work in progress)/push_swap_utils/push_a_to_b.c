/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:13:37 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/25 15:40:19 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_push(t_stack *stack, int push_value)
{
	int i;

	i = 0;
	while (stack)
	{
		if (stack->push == push_value)
			return (i);
		stack = stack->next;
		i++;
	}
	return(-1);
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->push != 0)
	{
		if (find_push(*stack_a, 0) > (ft_list_size(*stack_a) / 2))
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_b, stack_a);
}