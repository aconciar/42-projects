/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency_no_save.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:26:07 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/24 16:02:44 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_rrb_counter_b_no_save(t_stack *stack_b, int index, t_operator *operator)
{
	int	moves;
	int stack_size;

	stack_size = ft_list_size(stack_b);
	moves = 0;
	if ((index > find_biggest(stack_b) && find_biggest(stack_b) == stack_b->index) 
		|| (index < find_smallest(stack_b) && find_smallest(stack_b) == ft_list_last(stack_b)->index))
	{
		operator->rrb = 0;
		operator->rb = 0;
		return ;
	}
	if (index < find_smallest(stack_b))
	{
		while (stack_b->next && stack_b->index != find_smallest_after_index(stack_b, index))
		{
			moves++;
			stack_b = stack_b->next;
		}
		if (stack_b->index == find_smallest_after_index(stack_b, index))
		{
			moves++;
			stack_b = stack_b->next;
		}
	}
	else
	{
		while (stack_b->next && stack_b->index != find_biggest_before_index(stack_b, index))
		{
			moves++;
			stack_b = stack_b->next;
		}
	}
	operator->rrb = stack_size - moves;
	operator->rb = moves;
}


void	ra_rra_counter_a_no_save(t_stack *stack_a, int index, t_operator *operator)
{
	int	moves;
	int stack_size;

	stack_size = ft_list_size(stack_a);
	moves = 0;
	while (stack_a->index != index && stack_a->next)
	{
		moves++;
		stack_a = stack_a->next;
	}
	operator->rra = stack_size - moves;
	operator->ra = moves;
}

int	efficiency_counter_no_save(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	r_moves = 0;
	int	rr_moves = 0;
	t_operator	operator;
	ra_rra_counter_a_no_save(stack_a, index, &operator);
	rb_rrb_counter_b_no_save(stack_b, index, &operator);
	if (operator.ra < operator.rb)
	{
		operator.rr = operator.ra;
		operator.rb -= operator.ra;
		operator.ra = 0;
	}
	else
	{
		operator.rr = operator.rb;
		operator.ra -= operator.rb;
		operator.rb = 0;
	}
	if (operator.rra < operator.rrb)
	{
		operator.rrr = operator.rra;
		operator.rrb -= operator.rra;
		operator.rra = 0;
	}
	else
	{
		operator.rrr = operator.rrb;
		operator.rra -= operator.rrb;
		operator.rrb = 0;
	}
	r_moves += operator.ra + operator.rb + operator.rr;
	rr_moves += operator.rra + operator.rrb + operator.rrr;
	if (r_moves < rr_moves)
	{
		operator.rra = 0;
		operator.rrb = 0;
		operator.rrr = 0;
		return (r_moves);
	}
	else
	{
		operator.ra = 0;
		operator.rb = 0;
		operator.rr = 0;
		return (rr_moves);
	}
}