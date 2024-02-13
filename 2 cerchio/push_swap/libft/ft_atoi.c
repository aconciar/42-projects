/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:51:01 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/08 15:44:50 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_if_is_numeric(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i])
	{
		if (nptr[i] < 48 || nptr[i] > 57)
			if (nptr[i] != '-' && nptr[i] != '+')
				return (1);
		i++;
	}
	return (0);
}

long int	ft_atoi(const char *nptr, int i)
{
	int				counter_minus;
	long long int	c;

	counter_minus = 0;
	c = 0;
	if (ft_if_is_numeric(nptr) != 0)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		counter_minus++;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		c = (c * 10) + (nptr[i] - '0');
		i++;
	}
	if (counter_minus == 1)
		c = -c;
	return (c);
}

// int	main(int argc, char *argv[])
// {
// 	if (argc != 0)
// 		printf("%ld", ft_atoi(argv[1]));
// 	return (0);
// }
