/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:02:09 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/02 17:18:01 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_counter(int moves, t_stack *stack_a, int index)
{
	if (index > find_biggest(stack_a))
	{
		while (stack_a->next
			&& stack_a->index != find_biggest_before_index(stack_a, index))
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
		while (stack_a->next
			&& stack_a->index != find_smallest_after_index(stack_a, index))
		{
			moves++;
			stack_a = stack_a->next;
		}
	}
	return (moves);
}

void	ra_rra_counter_a(t_stack *stack_a, int index, t_operator **value)
{
	int	moves;
	int	stack_size;

	stack_size = ft_list_size(stack_a);
	moves = 0;
	if ((index > find_biggest(stack_a)
			&& find_biggest(stack_a) == ft_list_last(stack_a)->index)
		|| (index < find_smallest(stack_a)
			&& find_smallest(stack_a) == stack_a->index))
	{
		(*value)->rra = 0;
		(*value)->ra = 0;
		return ;
	}
	moves = moves_counter(0, stack_a, index);
	(*value)->rra = stack_size - moves;
	(*value)->ra = moves;
}

void	rb_rrb_counter_b(t_stack *stack_b, int index, t_operator **value)
{
	int	moves;
	int	stack_size;

	stack_size = ft_list_size(stack_b);
	moves = 0;
	if (stack_b->index == index)
	{
		(*value)->rrb = 0;
		(*value)->rb = 0;
		return ;
	}
	while (stack_b->index != index && stack_b->next)
	{
		moves++;
		stack_b = stack_b->next;
	}
	(*value)->rrb = stack_size - moves;
	(*value)->rb = moves;
}

void	efficiency_counter2(t_operator **value)
{
	if ((*value)->ra < (*value)->rb)
	{
		(*value)->rr = (*value)->ra;
		(*value)->rb -= (*value)->ra;
		(*value)->ra = 0;
	}
	else
	{
		(*value)->rr = (*value)->rb;
		(*value)->ra -= (*value)->rb;
		(*value)->rb = 0;
	}
	if ((*value)->rra < (*value)->rrb)
	{
		(*value)->rrr = (*value)->rra;
		(*value)->rrb -= (*value)->rra;
		(*value)->rra = 0;
	}
	else
	{
		(*value)->rrr = (*value)->rrb;
		(*value)->rra -= (*value)->rrb;
		(*value)->rrb = 0;
	}
}

void	efficiency_counter(t_stack *a, t_stack *b, int index, t_operator **val)
{
	int	r_moves;
	int	rr_moves;

	r_moves = 0;
	rr_moves = 0;
	rb_rrb_counter_b(b, index, val);
	ra_rra_counter_a(a, index, val);
	efficiency_counter2(val);
	r_moves += (*val)->ra + (*val)->rb + (*val)->rr;
	rr_moves += (*val)->rra + (*val)->rrb + (*val)->rrr;
	if (r_moves < rr_moves)
	{
		(*val)->rra = 0;
		(*val)->rrb = 0;
		(*val)->rrr = 0;
	}
	else
	{
		(*val)->ra = 0;
		(*val)->rb = 0;
		(*val)->rr = 0;
	}
}
