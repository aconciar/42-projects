/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/20 18:31:24 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_list *stack)
{
	int	min_value;
	int	current_value;

	min_value = INT_MAX;
	while (stack)
	{
		current_value = *(int *)(stack->content);
		if (current_value < min_value)
			min_value = current_value;
		stack = stack->next;
	}
	return (min_value);
}

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a))
	{
		if ((*(int *)(*stack_a)->content) == find_smallest(*stack_a))
			pb(stack_b, stack_a);
		else
			ra(stack_a);
	}
	while ((*stack_b))
		pa(stack_a, stack_b);
}
