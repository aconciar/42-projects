/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/09 18:43:25 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_b, stack_a, 1);
	pb(stack_b, stack_a, 1);
	three_numbers_a(stack_a);
	while ((*stack_b)->next)
		push_b_to_a(stack_b, stack_a);
	push_b_to_a(stack_b, stack_a);
	ft_smallest_on_top(stack_a);
}
