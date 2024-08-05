/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:09:26 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/22 17:25:46 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *str, int fd)
{
	size_t	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		i += ft_char(str[i], fd);
	return (i);
}
