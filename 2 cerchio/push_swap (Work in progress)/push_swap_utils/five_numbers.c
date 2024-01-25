/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/23 17:47:40 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_else_if(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		sa(stack_a);
		if ((*stack_a)->next->index > (*stack_a)->next->next->index)
		{
			ra(stack_a);
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	three_numbers_a(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		if ((*stack_b)->index < ft_list_last(*stack_a)->index)
			sb(stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > ft_list_last(*stack_a)->index)
		ra(stack_a);
	else
		ft_else_if(stack_a);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > ft_list_last(*stack_a)->index)
		ra(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index)
	{
		sa(stack_a);
		if ((*stack_a)->next->index > (*stack_a)->next->next->index)
		{
			ra(stack_a);
			sa(stack_a);
			rra(stack_a);
		}
	}
}
