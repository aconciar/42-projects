/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:39:26 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/22 17:19:14 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numero_spazi(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_unsigned(unsigned int n, int fd)
{
	int	sp;

	if (n >= 10)
	{
		ft_unsigned(n / 10, fd);
		ft_unsigned(n % 10, fd);
	}
	else
		ft_char(n + 48, fd);
	sp = numero_spazi(n);
	if (n == 0)
		sp++;
	return (sp);
}
