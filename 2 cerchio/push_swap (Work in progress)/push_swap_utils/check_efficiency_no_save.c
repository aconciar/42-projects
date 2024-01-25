/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency_no_save.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:26:07 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/25 16:10:21 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rra_counter_a_no_save(t_stack *stack_a, int index, t_operator *operator)
{
	int	moves;
	int stack_size;

	stack_size = ft_list_size(stack_a);
	moves = 0;
	if ((index > find_biggest(stack_a) && find_biggest(stack_a) == ft_list_last(stack_a)->index) 
		|| (index < find_smallest(stack_a) && find_smallest(stack_a) == stack_a->index))
	{
		operator->rra = 0;
		operator->ra = 0;
		return ;
	}
	if (index > find_biggest(stack_a))
	{
		while (stack_a->next && stack_a->index != find_biggest_before_index(stack_a, index))
		{
			moves++;
			stack_a = stack_a->next;
		}
		if (stack_a->index == find_biggest_before_index(stack_a, index))
		{
			moves++;
			stack_a = stack_a->next;
		}
	}
	else
	{
		while (stack_a->next && stack_a->index != find_smallest_after_index(stack_a, index))
		{
			moves++;
			stack_a = stack_a->next;
		}
	}
	operator->rra = stack_size - moves;
	// ft_printf("operator->rra : %d\n", operator->rra);
	operator->ra = moves;
	// ft_printf("operator->ra : %d\n", operator->ra);
}


void	rb_rrb_counter_b_no_save(t_stack *stack_b, int index, t_operator *operator)
{
	int	moves;
	int stack_size;

	stack_size = ft_list_size(stack_b);
	moves = 0;
	while (stack_b->index != index && stack_b->next)
	{
		moves++;
		stack_b = stack_b->next;
	}
	operator->rrb = stack_size - moves;
	// ft_printf("operator->rrb : %d\n", operator->rrb);
	operator->rb = moves;
	// ft_printf("operator->rb : %d\n", operator->rb);
}

int	efficiency_counter_no_save(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	r_moves;
	int	rr_moves;
	t_operator	operator;

	r_moves = 0;
	rr_moves = 0;
	// ft_printf("index : %d\n", index);
	rb_rrb_counter_b_no_save(stack_b, index, &operator);
	ra_rra_counter_a_no_save(stack_a, index, &operator);
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
	// ft_printf("r_moves : %d\n", r_moves);	
	// ft_printf("rr_moves : %d\n",rr_moves);
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