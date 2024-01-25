/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:44:10 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/12 17:46:51 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_numbers_a(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	two_numbers_b(t_stack **stack_b)
{
	if ((*stack_b)->index > (*stack_b)->next->index)
		sb(stack_b);
}

void	three_numbers_a(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index < ft_list_last(*stack_a)->index)
		sa(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->next->index > ft_list_last(*stack_a)->index)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->next->index < ft_list_last(*stack_a)->index)
		ra(stack_a);
	else if ((*stack_a)->next->index > (*stack_a)->index && (*stack_a)->next->index < ft_list_last(*stack_a)->index)
		return ;
	else if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->index < ft_list_last(*stack_a)->index)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->index > ft_list_last(*stack_a)->index)
		rra(stack_a);
}

void	three_numbers_b(t_stack **stack_b)
{
	if ((*stack_b)->index > (*stack_b)->next->index && (*stack_b)->index < ft_list_last(*stack_b)->index)
		sb(stack_b);
	else if ((*stack_b)->index > (*stack_b)->next->index && (*stack_b)->next->index > ft_list_last(*stack_b)->index)
	{
		sb(stack_b);
		rrb(stack_b);
	}
	else if ((*stack_b)->index > (*stack_b)->next->index && (*stack_b)->next->index < ft_list_last(*stack_b)->index)
		rb(stack_b);
	else if ((*stack_b)->next->index > (*stack_b)->index && (*stack_b)->next->index < ft_list_last(*stack_b)->index)
		return ;
	else if ((*stack_b)->index < (*stack_b)->next->index && (*stack_b)->index < ft_list_last(*stack_b)->index)
	{
		sb(stack_b);
		rb(stack_b);
	}
	else if ((*stack_b)->index < (*stack_b)->next->index && (*stack_b)->index > ft_list_last(*stack_b)->index)
		rrb(stack_b);
}
