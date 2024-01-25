/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:33:44 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/24 18:08:31 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_if_in(int index, int *array)
{
	int	i;

	i = 0;
	while (array[i] != -1)
	{
		if (array[i] == index)
			return (1);
		i++;
	}
	return (0);
}

int	*create_array(t_stack *stack, int size)
{
	int		*array;
	int		i;
	t_stack	*tmp;

	array = (int *)malloc(sizeof(int) * (ft_list_size(stack) + 1));
	i = 0;
	tmp = stack;
	while (tmp && i < size)
	{
		array[i] = tmp->index;
		i++;
		tmp = tmp->next;
	}
	return (array);
}

void	lis_init(t_stack **stack)
{
	int	*array_lis;
	t_stack *temp;

	temp = *stack;
	array_lis = ft_lis(create_array(*stack, ft_list_size(*stack)), ft_list_size(*stack), 1, 0);
	while (temp)
	{
		if (ft_if_in(temp->index, array_lis) == 1)
			temp->push = 1;
		temp = temp->next;
	}
}

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

void	index_init(t_stack **stack)
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
		a = a->next;
		i++;
	}
	lis_init(stack);
}
