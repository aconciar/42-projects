/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_efficiency.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:02:09 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/25 16:10:12 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rra_counter_a(t_stack *stack_a, int index, t_operator **value)
{
	int	moves;
	int stack_size;

	stack_size = ft_list_size(stack_a);
	moves = 0;
	if ((index > find_biggest(stack_a) && find_biggest(stack_a) == ft_list_last(stack_a)->index) 
		|| (index < find_smallest(stack_a) && find_smallest(stack_a) == stack_a->index))
	{
		(*value)->rra = 0;
		(*value)->ra = 0;
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
	(*value)->rra = stack_size - moves;
	// ft_printf("(*value)->rra : %d\n", (*value)->rra);
	(*value)->ra = moves;
	// ft_printf("(*value)->ra : %d\n", (*value)->ra);
}

void	rb_rrb_counter_b(t_stack *stack_b, int index, t_operator **value)
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
	(*value)->rrb = stack_size - moves;
	// ft_printf("(*value)->rrb : %d\n", (*value)->rrb);
	(*value)->rb = moves;
	// ft_printf("(*value)->rb : %d\n", (*value)->rb);
}

void	efficiency_counter(t_stack *stack_a, t_stack *stack_b, int index, t_operator **value)
{
	int	r_moves;
	int	rr_moves;

	r_moves = 0;
	rr_moves = 0;
	// ft_printf("index : %d\n", index);
	rb_rrb_counter_b(stack_b, index, value);
	ra_rra_counter_a(stack_a, index, value);
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
	// ft_printf("r_moves : %d\n", r_moves);	
	// ft_printf("rr_moves : %d\n",rr_moves);
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

void	check_efficiency(t_stack *stack_b, t_stack *stack_a, t_operator *value)
{
	t_stack	*temp_a;
	t_stack *temp_b;
	int		min_moves;
	int		current_moves;
	int		index_min_value;

	min_moves = INT_MAX;
	temp_a = stack_a;
	temp_b = stack_b;
	while (stack_b)
	{
		// ft_printf("\n\n\nciclo\n");
		current_moves = efficiency_counter_no_save(temp_a, temp_b, stack_b->index);
		// ft_printf("current_moves : %d\n", current_moves);
		// ft_printf("min_moves : %d\n", min_moves);
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
			index_min_value = stack_b->index;
			// ft_printf("index_min_value1 : %d\n", index_min_value);
		}
		stack_b = stack_b->next;
	}
	// ft_printf("index_min_value2 : %d\n", index_min_value);
	efficiency_counter(temp_a, temp_b, index_min_value, &value);
}
