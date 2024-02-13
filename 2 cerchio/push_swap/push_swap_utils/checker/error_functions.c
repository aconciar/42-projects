/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:38:59 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/09 17:39:18 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line)
		free(line);
	get_next_line(-42);
	ft_free_list(*stack_a);
	ft_free_list(*stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_ko(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line)
		free(line);
	get_next_line(-42);
	ft_free_list(*stack_a);
	ft_free_list(*stack_b);
	write(2, "KO\n", 6);
	exit (1);
}
