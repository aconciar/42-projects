/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:34:22 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/25 16:46:54 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_one(int *array, int size)
{
	int	j;

	j = -1;
	while (++j < size)
		array[j] = 1;
}

int	arr_biggest(int *array, int size)
{
	int		max_value;
	int		current_value;
	int		i;

	max_value = INT_MIN;
	i = 0;
	while (i < size)
	{
		current_value = array[i];
		if (current_value > max_value)
			max_value = current_value;
		i++;
	}
	return (max_value);
}

int	ft_index(int *args, int num)
{
	int	i;

	i = 0;
	while (args[i] && args[i] != num)
		i++;
	return (i);
}

int	*build_array(int *length, int *array, int *sub_sequence, int size)
{
	int	biggest_length;
	int	*ret;
	int	p;
	int	u;

	biggest_length = arr_biggest(length, size);
	ret = (int *)malloc(sizeof(int) * (biggest_length + 1));
	p = biggest_length;
	u = sub_sequence[ft_index(length, biggest_length)];
	ret[p] = -1;
	p--;
	ret[p] = array[ft_index(length, biggest_length)];
	p--;
	while (p >= 0)
	{
		ret[p] = array[u];
		u = sub_sequence[u];
		p--;
	}
	return (ret);
}

int	*ft_lis(int *array, int size, int i, int j)
{
	int	*sub_sequence;
	int	*length;

	length = (int *)malloc(sizeof(int) * size);
	sub_sequence = (int *)malloc(sizeof(int) * size);
	init_one(length, size);
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i])
			{
				if (length[j] == length[i])
				{
					length[i] = length[j] + 1;
					sub_sequence[i] = ft_index(array, array[j]);
				}
			}
			j++;
		}
		i++;
	}
	return (build_array(length, array, sub_sequence, size));
}
