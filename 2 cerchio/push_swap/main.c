/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:02 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/21 17:45:18 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**mat;
	int		i;
	int		*num;
	char	*str;

	str = ft_calloc(1, 1);
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		if (check_input(argv[1]) != 0)
			return (ft_printf("Error1\n"));
		mat = ft_split(argv[1], ' ');
		i = 0;
		while (mat[i])
		{
			num = malloc(sizeof(int));
			*num = atoi(mat[i]);
			ft_lstadd_back(&stack_a, ft_lstnew(num));
			i++;
		}
	}
	else if (argc < 2)
		return (ft_printf("Error2\n"));
	else
	{
		while (argv[++i])
			str = ft_strjoin(str, ft_strjoin(argv[i], " "));
		ft_printf("str : %s", str);
		if (check_input(str) != 0)
			return (ft_printf("Error3\n"));
		i = 0;
		while (argv[++i])
		{
			num = malloc(sizeof(int));
			*num = atoi(argv[i]);
			ft_lstadd_back(&stack_a, ft_lstnew(num));
		}
		i--;
	}
	if (i == 2)
		two_numbers_a(&stack_a);
	else if (i == 3)
		three_numbers_a(&stack_a);
	else if (i == 5)
		five_numbers(&stack_a, &stack_b);
	else
		insertion_sort(&stack_a, &stack_b);
	// while (stack_a)
	// {	
	// 	ft_printf("%d\n", (*(int *)(stack_a->content)));
	// 	stack_a = stack_a->next;
	// }
	// ft_printf("\n");
	// while (stack_b)
	// {	
	// 	ft_printf("%d\n", (*(int *)(stack_b->content)));
	// 	stack_b = stack_b->next;
	// }
	return (0);
}
