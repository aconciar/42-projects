/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:24:22 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/20 17:24:41 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting(t_list** stack_a, t_list **stack_b, int moves, int i)
{
	int	a;
	int c;
	int	t;

	a = i;
	c = 1;
	while (a > 0)
	{
		if ((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content))
		{
			sa(stack_a);
			moves++;
		}
		pb(stack_b, stack_a);
		moves++;
		if ((*stack_b)->next && (*(int *)(*stack_b)->content) < (*(int *)(*stack_b)->next->content))
		{
			if ((*(int *)(*stack_b)->content) > (*(int *)ft_lstlast(*stack_b)->content))
				sb(stack_b);
			else
				rb(stack_b);
			moves++;
		}
		a--;
	}
	a = i - 1;
	if (a == 3)
		i--;
	while (a > 0)
	{
		if ((*(int *)(*stack_a)->content) > (*(int *)ft_lstlast(*stack_a)->content))
		{
			rra(stack_a);
			moves++;
		}
		if ((*(int *)(*stack_a)->content) < (*(int *)(*stack_a)->next->content))
		{
			sa(stack_a);
			moves++;
		}
		t = c;
		while (t > 0)
		{
			rra(stack_a);
			if ((*(int *)(*stack_a)->content) < (*(int *)(*stack_a)->next->content))
			{
				sa(stack_a);
				moves++;
			}
			pb(stack_b, stack_a);
			moves += 2;
			t--;
		}
		ra(stack_a);
		moves ++;
		t = c;
		while (t > 0)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			moves ++;
			t--;
		}
		c++;
		a--;
	}
	a = i;
	while (a > 0)
	{
		c = 0;
		if ((*(int *)(*stack_a)->content) > (*(int *)(*stack_b)->content))
		{
			pa(stack_a, stack_b);
			moves++;
		}
		else
		{
			while ((*(int *)(*stack_b)->content) < (*(int *)ft_lstlast(*stack_a)->content))
			{
				rra(stack_a);
				moves++;
				c++;
			}
			pa(stack_a, stack_b);
			moves++;
			while(c >= 0)
			{
				ra(stack_a);
				moves++;
				c--;
			}
		}
		a--;
	}
	return (moves);
}
