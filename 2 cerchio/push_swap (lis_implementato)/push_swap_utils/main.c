/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:02 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/25 15:35:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (stack_init(argc, argv, &stack_a) == 1)
		return (ft_printf("Error\n"));
	index_init(&stack_a);
	if (ft_list_size(stack_a) == 2 && check_order(stack_a) == 1)
		two_numbers_a(&stack_a);
	else if (ft_list_size(stack_a) == 3 && check_order(stack_a) == 1)
		three_numbers_a(&stack_a);
	else if (ft_list_size(stack_a) == 5 && check_order(stack_a) == 1)
		five_numbers(&stack_a, &stack_b);
	else if (check_order(stack_a) == 1)
		sorting(&stack_a, &stack_b);
	// ft_print_stack(stack_a);
	// ft_printf("\nSTACK_B\n");
	// ft_print_stack(stack_b);
	ft_free_list(stack_a);
	return (0);
}

