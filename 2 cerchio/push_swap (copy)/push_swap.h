/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:39:39 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/20 18:08:06 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
#include <limits.h>

void	pa(t_list **stack, t_list **node);
void	pb(t_list **stack, t_list **node);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
int		sorting(t_list** stack_a, t_list** stack_b, int moves, int i);
void	three_numbers_a(t_list **stack_a);
void	three_numbers_b(t_list **stack_b);
void	five_numbers(t_list **stack_a, t_list **stack_b);
void	insertion_sort(t_list **stack_a, t_list **stack_b);

#endif