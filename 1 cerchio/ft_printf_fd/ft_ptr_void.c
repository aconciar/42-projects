/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:11:52 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/22 17:18:20 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cont_ptr(uintptr_t nbr, int len)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= len;
	}
	return (i);
}

void	ft_put_ptr(uintptr_t num, int fd)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16, fd);
		ft_put_ptr(num % 16, fd);
	}
	else
	{
		if (num <= 9)
			ft_char((num + '0'), fd);
		else
			ft_char((num - 10 + 'a'), fd);
	}
}

int	ft_ptr_void(uintptr_t ptr, int fd)
{
	int	i;

	i = 0;
	if (ptr == 0)
	{
		ft_string("(nil)", fd);
		return (5);
	}
	i += write(fd, "0x", 2);
	ft_put_ptr(ptr, fd);
	i += cont_ptr(ptr, 16);
	return (i);
}
