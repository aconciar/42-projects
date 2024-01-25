/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:15:40 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/25 16:32:55 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_operations_b(t_stack **stack_b, t_stack **stack_a, t_operator operator)
{
	while (operator.rr > 0)
	{
		rr(stack_a, stack_b);
		operator.rr--;
	}
	while (operator.rb > 0)
	{
		rb(stack_b);
		operator.rb--;
	}
	while (operator.ra > 0)
	{
		ra(stack_a);
		operator.ra--;
	}
}

void	rr_operations_b(t_stack **stack_b, t_stack **stack_a, t_operator operator)
{
	while (operator.rrr > 0)
	{
		rrr(stack_a, stack_b);
		operator.rrr--;
	}
	while (operator.rrb > 0)
	{
		rrb(stack_b);
		operator.rrb--;
	}
	while (operator.rra > 0)
	{
		rra(stack_a);
		operator.rra--;
	}
}

void	push_b_to_a(t_stack **stack_b, t_stack **stack_a)
{
	t_operator operator;

	check_efficiency(*stack_b, *stack_a, &operator);
	// ft_printf("operator.rr : %d\n", operator.rr);
	// ft_printf("operator.ra : %d\n", operator.ra);
	// ft_printf("operator.rb : %d\n", operator.rb);
	// ft_printf("operator.rrr : %d\n", operator.rrr);
	// ft_printf("operator.rra : %d\n", operator.rra);
	// ft_printf("operator.rrb : %d\n", operator.rrb);
	r_operations_b(stack_b, stack_a, operator);
	rr_operations_b(stack_b, stack_a, operator);
	pa(stack_a, stack_b);
	if ((*stack_a)->index == find_biggest(*stack_a))
		ra(stack_a);
}