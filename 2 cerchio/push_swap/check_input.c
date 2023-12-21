/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/21 17:59:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dup(char *str, int i)
{
	char	*buf1;
	char	*buf2;
	int		a;
	int		t;

	t = i;
	a = 0;
	while (str[t] != ' ' && str[t])
		t++;
	buf1 = ft_calloc(1, t + 1);
	while (str[i] != ' ' && str[i])
	{
		buf1[a] = str[i];
		a++;
		i++;
	}
	i++;
	t = 0;
	while (str[i]!= ' ' && str[i])
	{
		i++;
		t++;
	}
	buf2 = ft_calloc (1, t + 1);
	a = 0;
	while (str[i]!= ' ' && str[i])
	{
		buf1[a] = str[i];
		a++;
		i++;
	}
	return (ft_strcmp (buf1, buf2));
}

int	check_input(char *str)
{
	int	i;
	int t;
	int	cont;

	cont = 0;
	t = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == 32))
		{
			if ((str[i] >= '0' && str[i] <= '9') && is_dup(str, i) != 0)
				return (1);
		}
		else
			t = 1;
		i++;
	}
	return (t);
}
