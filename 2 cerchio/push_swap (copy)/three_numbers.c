/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:44:10 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/20 18:02:03 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers_a(t_list **stack_a)
{
	if (((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->content) < (*(int *)ft_lstlast(*stack_a)->content)))
		sa(stack_a);
	else if (((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->next->content) > (*(int *)ft_lstlast(*stack_a)->content)))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->next->content) < (*(int *)ft_lstlast(*stack_a)->content)))
		ra(stack_a);
	else if (((*(int *)(*stack_a)->next->content) > (*(int *)(*stack_a)->content)) && ((*(int *)(*stack_a)->next->content) < (*(int *)ft_lstlast(*stack_a)->content)))
		return ;
	else if (((*(int *)(*stack_a)->content) < (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->content) < (*(int *)ft_lstlast(*stack_a)->content)))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (((*(int *)(*stack_a)->content) < (*(int *)(*stack_a)->next->content)) && ((*(int *)(*stack_a)->content) > (*(int *)ft_lstlast(*stack_a)->content)))
		rra(stack_a);
}

void	three_numbers_b(t_list **stack_b)
{
	if (((*(int *)(*stack_b)->content) > (*(int *)(*stack_b)->next->content)) && ((*(int *)(*stack_b)->content) < (*(int *)ft_lstlast(*stack_b)->content)))
		sb(stack_b);
	else if (((*(int *)(*stack_b)->content) > (*(int *)(*stack_b)->next->content)) && ((*(int *)(*stack_b)->next->content) > (*(int *)ft_lstlast(*stack_b)->content)))
	{
		sb(stack_b);
		rrb(stack_b);
	}
	else if (((*(int *)(*stack_b)->content) > (*(int *)(*stack_b)->next->content)) && ((*(int *)(*stack_b)->next->content) < (*(int *)ft_lstlast(*stack_b)->content)))
		rb(stack_b);
	else if (((*(int *)(*stack_b)->next->content) > (*(int *)(*stack_b)->content)) && ((*(int *)(*stack_b)->next->content) < (*(int *)ft_lstlast(*stack_b)->content)))
		return ;
	else if (((*(int *)(*stack_b)->content) < (*(int *)(*stack_b)->next->content)) && ((*(int *)(*stack_b)->content) < (*(int *)ft_lstlast(*stack_b)->content)))
	{
		sb(stack_b);
		rb(stack_b);
	}
	else if (((*(int *)(*stack_b)->content) < (*(int *)(*stack_b)->next->content)) && ((*(int *)(*stack_b)->content) > (*(int *)ft_lstlast(*stack_b)->content)))
		rrb(stack_b);
}
