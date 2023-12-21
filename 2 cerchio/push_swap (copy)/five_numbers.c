/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/20 18:04:46 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_numbers(t_list **stack_a, t_list **stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	three_numbers_a(stack_a);
	if ((*(int *)(*stack_b)->content) < (*(int *)(*stack_b)->next->content))
		sb(stack_b);
	pa(stack_a, stack_b);
	if ((*(int *)(*stack_a)->content) > (*(int *)ft_lstlast(*stack_a)->content))
		ra(stack_a);
	else if ((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content))
	{
		sa(stack_a);
		if ((*(int *)(*stack_a)->next->content) > (*(int *)(*stack_a)->next->next->content))
			sa(&(*stack_a)->next);
	}
	pa(stack_a, stack_b);
	if ((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content))
	{
		sa(stack_a);
		if ((*(int *)(*stack_a)->next->content) > (*(int *)(*stack_a)->next->next->content))
			sa(&(*stack_a)->next);
	}
}