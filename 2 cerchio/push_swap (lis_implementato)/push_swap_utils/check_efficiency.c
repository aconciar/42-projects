/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:02:09 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/24 18:35:53 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_rrb_counter_b(t_stack *stack_b, int index, t_operator **value)
{
	int	moves;
	int stack_size;

	stack_size = ft_list_size(stack_b);
	moves = 0;
	if ((index > find_biggest(stack_b) && find_biggest(stack_b) == stack_b->index) 
		|| (index < find_smallest(stack_b) && find_smallest(stack_b) == ft_list_last(stack_b)->index))
	{
		(*value)->rrb = 0;
		(*value)->rb = 0;
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
	(*value)->rrb = stack_size - moves;
	(*value)->rb = moves;
}

void	ra_rra_counter_a(t_stack *stack_a, int index, t_operator **value)
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
	(*value)->rra = stack_size - moves;
	(*value)->ra = moves;
}

void	efficiency_counter(t_stack *stack_a, t_stack *stack_b, int index, t_operator **value)
{
	int	r_moves = 0;
	int	rr_moves = 0;

	ra_rra_counter_a(stack_a, index, value);
	rb_rrb_counter_b(stack_b, index, value);
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
	r_moves += (*value)->ra + (*value)->rb + (*value)->rr;
	rr_moves += (*value)->rra + (*value)->rrb + (*value)->rrr;
	if (r_moves < rr_moves)
	{
		(*value)->rra = 0;
		(*value)->rrb = 0;
		(*value)->rrr = 0;
	}
	else
	{
		(*value)->ra = 0;
		(*value)->rb = 0;
		(*value)->rr = 0;
	}
}

void	check_efficiency(t_stack *stack_a, t_stack *stack_b, t_operator *value)
{
	t_stack	*temp_a;
	t_stack *temp_b;
	int		min_moves;
	int		current_moves;
	int		index_min_value;

	min_moves = INT_MAX;
	temp_a = stack_a;
	temp_b = stack_b;
	while (stack_a)
	{
		if (stack_a->push == 0)
		{
			current_moves = efficiency_counter_no_save(temp_a, temp_b, stack_a->index);
			if (current_moves < min_moves)
			{
				min_moves = current_moves;
				index_min_value = stack_a->index;
			}
		}
		stack_a = stack_a->next;
	}
	efficiency_counter(temp_a, temp_b, index_min_value, &value);
}
