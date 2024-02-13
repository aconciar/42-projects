/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency_no_save.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:26:07 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/02 17:20:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_counter_no_save(int moves, t_stack *stack_a, int index)
{
	if (index > find_biggest(stack_a))
	{
		while (stack_a->next && stack_a->index
			!= find_biggest_before_index(stack_a, index))
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
		while (stack_a->next && stack_a->index
			!= find_smallest_after_index(stack_a, index))
		{
			moves++;
			stack_a = stack_a->next;
		}
	}
	return (moves);
}

void	a_no_save(t_stack *stack_a, int index, t_operator *operator)
{
	int	moves;
	int	stack_size;

	stack_size = ft_list_size(stack_a);
	if ((index > find_biggest(stack_a)
			&& find_biggest(stack_a) == ft_list_last(stack_a)->index)
		|| (index < find_smallest(stack_a)
			&& find_smallest(stack_a) == stack_a->index))
	{
		operator->rra = 0;
		operator->ra = 0;
		return ;
	}
	moves = moves_counter_no_save(0, stack_a, index);
	operator->rra = stack_size - moves;
	operator->ra = moves;
}

void	b_no_save(t_stack *stack_b, int index, t_operator *operator)
{
	int	moves;
	int	stack_size;

	stack_size = ft_list_size(stack_b);
	moves = 0;
	if (stack_b->index == index)
	{
		operator->rrb = 0;
		operator->rb = 0;
		return ;
	}
	while (stack_b->index != index && stack_b->next)
	{
		moves++;
		stack_b = stack_b->next;
	}
	operator->rrb = stack_size - moves;
	operator->rb = moves;
}

void	efficiency_counter_nosave2(t_operator	*operator)
{
	if (operator->ra < operator->rb)
	{
		operator->rr = operator->ra;
		operator->rb -= operator->ra;
		operator->ra = 0;
	}
	else
	{
		operator->rr = operator->rb;
		operator->ra -= operator->rb;
		operator->rb = 0;
	}
	if (operator->rra < operator->rrb)
	{
		operator->rrr = operator->rra;
		operator->rrb -= operator->rra;
		operator->rra = 0;
	}
	else
	{
		operator->rrr = operator->rrb;
		operator->rra -= operator->rrb;
		operator->rrb = 0;
	}
}

int	efficiencycounter_nosave(t_stack *stack_a, t_stack *stack_b, int index)
{
	int			r_moves;
	int			rr_moves;
	t_operator	operator;

	r_moves = 0;
	rr_moves = 0;
	b_no_save(stack_b, index, &operator);
	a_no_save(stack_a, index, &operator);
	efficiency_counter_nosave2(&operator);
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
