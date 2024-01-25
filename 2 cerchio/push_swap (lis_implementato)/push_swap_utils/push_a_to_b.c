/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:13:37 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/25 15:39:11 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_operations(t_stack **stack_a, t_stack **stack_b, t_operator operator)
{
	while (operator.rr > 0)
	{
		rr(stack_a, stack_b);
		operator.rr--;
	}
	while (operator.ra > 0)
	{
		ra(stack_a);
		operator.ra--;
	}
	while (operator.rb > 0)
	{
		rb(stack_b);
		operator.rb--;
	}
}

void	rr_operations(t_stack **stack_a, t_stack **stack_b, t_operator operator)
{
	while (operator.rrr > 0)
	{
		rrr(stack_a, stack_b);
		operator.rrr--;
	}
	while (operator.rra > 0)
	{
		rra(stack_a);
		operator.rra--;
	}
	while (operator.rrb > 0)
	{
		rrb(stack_b);
		operator.rrb--;
	}
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_operator operator;

	check_efficiency(*stack_a, *stack_b, &operator);
	r_operations(stack_a, stack_b, operator);
	rr_operations(stack_a, stack_b, operator);
	pb(stack_b, stack_a);
	if ((*stack_b)->index == find_smallest(*stack_b))
		rb(stack_b);
}