/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:15:40 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/02 21:23:03 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_efficiency(t_stack *stack_b, t_stack *stack_a, t_operator *value)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		min_moves;
	int		current_moves;
	int		index_min_value;

	min_moves = INT_MAX;
	tmp_a = stack_a;
	tmp_b = stack_b;
	while (stack_b)
	{
		current_moves = efficiencycounter_nosave(tmp_a, tmp_b, stack_b->index);
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
			index_min_value = stack_b->index;
		}
		stack_b = stack_b->next;
	}
	efficiency_counter(tmp_a, tmp_b, index_min_value, &value);
}

void	r_operations_b(t_stack **b, t_stack **a, t_operator operator)
{
	while (operator.rr > 0)
	{
		rr(a, b, 1);
		operator.rr--;
	}
	while (operator.rb > 0)
	{
		rb(b, 1);
		operator.rb--;
	}
	while (operator.ra > 0)
	{
		ra(a, 1);
		operator.ra--;
	}
}

void	rr_operations_b(t_stack **b, t_stack **a, t_operator operator)
{
	while (operator.rrr > 0)
	{
		rrr(a, b, 1);
		operator.rrr--;
	}
	while (operator.rrb > 0)
	{
		rrb(b, 1);
		operator.rrb--;
	}
	while (operator.rra > 0)
	{
		rra(a, 1);
		operator.rra--;
	}
}

void	push_b_to_a(t_stack **stack_b, t_stack **stack_a)
{
	t_operator	operator;

	check_efficiency(*stack_b, *stack_a, &operator);
	r_operations_b(stack_b, stack_a, operator);
	rr_operations_b(stack_b, stack_a, operator);
	pa(stack_a, stack_b, 1);
	if ((*stack_a)->index == find_biggest(*stack_a))
		ra(stack_a, 1);
}
