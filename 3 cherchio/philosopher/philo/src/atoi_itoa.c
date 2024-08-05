/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:05:53 by andrea            #+#    #+#             */
/*   Updated: 2024/06/21 17:52:03 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *nptr, int i)
{
	int				counter_minus;
	long long int	c;

	counter_minus = 0;
	c = 0;
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

size_t	n_sp(int nbr)
{
	size_t	i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*zero(void)
{
	char	*str;

	str = calloc(1, 2);
	*(str + 0) = 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	size_t		sp;

	nb = n;
	sp = n_sp(n);
	if (n < 0)
	{
		sp++;
		nb *= -1;
	}
	str = (char *)malloc(sizeof(char) * (sp + 1));
	if (n == 0)
		return (zero());
	if (str == NULL)
		return (NULL);
	*(str + (sp)) = '\0';
	while (sp--)
	{
		*(str + sp) = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
