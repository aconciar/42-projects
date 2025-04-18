/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:14:24 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/09 15:54:32 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_more_than_one_arg(char *argv[], t_stack **stack_a, int i, int num)
{
	char	*str;
	char	*str2;

	str = NULL;
	str2 = NULL;
	while (argv[++i])
	{
		str = ft_strjoin(argv[i], " ");
		str2 = ft_strjoinps(str2, str);
		free(str);
	}
	if (check_input(str2, 0) != 0)
	{
		free(str2);
		return (1);
	}
	free(str2);
	i = 0;
	while (argv[++i])
	{
		num = ft_atoi(argv[i], 0);
		ft_list_addback(stack_a, ft_create_node(num));
	}
	return (0);
}

void	if_just_one_arg(char *argv[], t_stack **stack_a)
{
	char	**mat;
	int		num;
	int		i;

	mat = ft_split(argv[1], ' ');
	i = 0;
	while (mat[i])
	{
		num = ft_atoi(mat[i], 0);
		ft_list_addback(stack_a, ft_create_node(num));
		i++;
	}
	free_mat(mat, 0);
}

int	stack_init(int argc, char *argv[], t_stack **stack_a)
{
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) < 1)
			exit (1);
		if (check_input(argv[1], 0) != 0)
			return (1);
		if_just_one_arg(argv, stack_a);
	}
	else if (argc < 2)
		exit (1);
	else
		return (if_more_than_one_arg(argv, stack_a, 0, 0));
	return (0);
}
