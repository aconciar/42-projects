/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:16:10 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/09 17:36:22 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*free_and_return(char *str_free, char *str_return)
{
	free(str_free);
	return (str_return);
}

char	*ft_check_operations(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(stack_b, stack_a, 0);
	else if (ft_strcmp(line, "sa") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(stack_a, stack_b, 0);
	else
		ft_error(stack_a, stack_b, line);
	return (free_and_return(line, get_next_line(0)));
}

void	ft_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	while (line && *line != '\n')
		line = ft_check_operations(stack_a, stack_b, line);
	free(line);
	if (check_order(*stack_a) == 1)
		ft_ko(stack_a, stack_b, line);
	else if (*stack_b)
		ft_error(stack_a, stack_b, line);
	else
		ft_printf("OK\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	line = get_next_line(0);
	if (stack_init(argc, argv, &stack_a) == 1)
		ft_error(&stack_a, &stack_b, line);
	index_init(&stack_a, 1, 1);
	if (!line && check_order(stack_a) == 1)
		ft_error(&stack_a, &stack_b, line);
	else if (!line && check_order(stack_a) == 0)
		ft_printf("OK\n");
	else
		ft_check(&stack_a, &stack_b, line);
	ft_free_list(stack_a);
	return (0);
}
