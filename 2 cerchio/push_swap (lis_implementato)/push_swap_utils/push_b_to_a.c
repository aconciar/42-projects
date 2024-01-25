/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:15:40 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/25 15:38:35 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_else(t_stack **stack_a, t_stack **stack_b)
{
	if (find_value(*stack_a, (*stack_b)->index + 1) == 1)
		while ((*stack_a)->index != (*stack_b)->index + 1)
		{
			if (find_eff(*stack_a, (*stack_b)->index + 1) > (ft_list_size(*stack_a) / 2))
				rra(stack_a);
			else
				ra(stack_a);
		}
	else
		while ((*stack_b)->index > (*stack_a)->index)
		{
			if (find_eff(*stack_a, find_biggest_before_index(*stack_a, (*stack_b)->index)) > (ft_list_size(*stack_a) / 2))
				rra(stack_a);
			else
				ra(stack_a);
		}
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->index > find_biggest(*stack_a) || (*stack_b)->index < find_smallest(*stack_a))
		while (ft_list_last(*stack_a)->index != find_biggest(*stack_a))
		{
			if (find_eff(*stack_a, find_biggest(*stack_a)) > (ft_list_size(*stack_a) / 2))
				rra(stack_a);
			else
				ra(stack_a);
		}
	else
		ft_else(stack_a, stack_b);
	pa(stack_a, stack_b);
}