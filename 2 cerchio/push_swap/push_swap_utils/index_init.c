/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:33:44 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/06 18:35:45 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack **stack)
{
	int		min_value;
	int		current_value;
	t_stack	*temp;

	min_value = INT_MAX;
	temp = *stack;
	while (temp)
	{
		current_value = temp->value;
		if (current_value < min_value && temp->has_index == 0)
			min_value = current_value;
		temp = temp->next;
	}
	return (min_value);
}

void	index_init(t_stack **stack, int c, int t)
{
	int		i;
	int		smallest;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = *stack;
	while (a)
	{
		b = *stack;
		smallest = find_index(&b);
		ft_list_find_node(b, smallest)->index = i;
		ft_list_find_node(b, smallest)->has_index = 1;
		ft_list_find_node(b, smallest)->chunk = c;
		a = a->next;
		if (t == ft_list_size(*stack) / 4)
		{
			c++;
			t = 0;
		}
		t++;
		i++;
	}
}
