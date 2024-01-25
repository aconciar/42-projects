/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:02 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/23 17:04:08 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**mat;
	int		i;
	int		num;
	char	*str = NULL;
	char	*str2 = NULL;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		if (check_input(argv[1]) != 0)
			return (ft_printf("Error\n"));
		mat = ft_split(argv[1], ' ');
		i = 0;
		while (mat[i])
		{
			num = atoi(mat[i]);
			ft_list_addback(&stack_a, ft_create_node(num));
			i++;
		}
		free_mat(mat);
	}
	else if (argc < 2)
		return (0);
	else
	{
		while (argv[++i])
		{
			str = ft_strjoin(argv[i], " ");
			str2 = ft_strjoingnl(str2, str);
			free(str);
		}
		if (check_input(str2) != 0)
		{
			free(str2);
			return (ft_printf("Error\n"));
		}
		free(str2);
		i = 0;
		while (argv[++i])
		{
			num = atoi(argv[i]);
			ft_list_addback(&stack_a, ft_create_node(num));
		}
		i--;
	}
	chunk_init(&stack_a);
	if (i == 2 && check_order(stack_a) == 1)
		two_numbers_a(&stack_a);
	else if (i == 3 && check_order(stack_a) == 1)
		three_numbers_a(&stack_a);
	else if (i == 5 && check_order(stack_a) == 1)
		five_numbers(&stack_a, &stack_b);
	else if (check_order(stack_a) == 1)
		insertion_sort(&stack_a, &stack_b);
	// while (stack_a)
	// {
	// 	ft_printf("%d\n", stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	// ft_printf("\n");
	// while (stack_b)
	// {
	// 	ft_printf("%d\n", stack_b->index);
	// 	stack_b = stack_b->next;
	// }
	ft_free_list(stack_a);
	return (0);
}
