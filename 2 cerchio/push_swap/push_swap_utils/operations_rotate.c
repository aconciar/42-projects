/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:17:47 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/06 18:36:58 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack, int i)
{
	t_stack	*value;

	if (ft_list_size(*stack) < 2)
		return ;
	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	if (i == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **stack, int i)
{
	t_stack	*value;

	if (ft_list_size(*stack) < 2)
		return ;
	value = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	value->next = NULL;
	ft_list_addback(stack, value);
	if (i == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (ft_list_size(*stack_a) < 2 || ft_list_size(*stack_b) < 2)
		return ;
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (i == 1)
		ft_printf("rr\n");
}
