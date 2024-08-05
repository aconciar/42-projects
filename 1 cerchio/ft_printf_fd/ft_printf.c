/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:00:08 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/22 17:26:17 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	cont_hex(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_type_var(va_list temp, va_list arg, char c, int fd)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_char(va_arg(arg, int), fd);
	if (c == 's')
		i += ft_string(va_arg(arg, char *), fd);
	if (c == 'p')
		i += ft_ptr_void(va_arg(arg, uint64_t), fd);
	if (c == 'i' || c == 'd')
		i += ft_dec(va_arg(arg, int), fd);
	if (c == 'u')
		i += ft_unsigned(va_arg(arg, unsigned int), fd);
	if (c == 'x' || c == 'X')
	{
		i += cont_hex(va_arg(temp, unsigned int));
		if (c == 'x')
			i += putnbr_hex(va_arg(arg, unsigned int), "0123456789abcdef", fd);
		else
			i += putnbr_hex(va_arg(arg, unsigned int), "0123456789ABCDEF", fd);
	}
	if (c == '%')
		i += ft_char('%', fd);
	return (i);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	temp;
	va_list	arg;	
	int		len;
	int		i;

	va_start(temp, str);
	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_type_var(temp, arg, str[i], fd);
		}
		else
			len += ft_char(str[i], fd);
		i++;
	}
	va_end(arg);
	va_end(temp);
	return (len);
}

// int	main()
// {
// 	int			len;
// 	char		c;
// 	char		*s;
// 	void		*p;
// 	int			i;
// 	unsigned int u;
// 	int			x;
// 	int			X;

// 	p = NULL;
// 	c = 'K';
// 	s = NULL;
// 	i = -2147483648;
// 	u = 0;
// 	x = 10;
// 	X = 11;
// 	/*CHAR*/
// 	len = ft_printf(1, "%c\n", c);
// 	printf ("len 1 : %d\n", len);
// 	len = printf("%c\n", c);
// 	printf ("len 2 : %d\n\n\n", len);
// 	/*STRINGA*/
// 	len = ft_printf(1, "%s\n", s);
// 	printf ("len 1 : %d\n", len);
// 	len = printf("%s\n", s);
// 	printf ("len 2 : %d\n\n\n", len);
// 	/*PTR VOID*/
// 	len = ft_printf(1, "%p\n", p);
// 	printf ("len 1 : %d\n", len);
// 	len = printf("%p\n", p);
// 	printf ("len 2 : %d\n\n\n", len);
// 	/*INTERO*/
// 	len = ft_printf(1, "%i\n", i);
// 	printf ("len 1 : %d\n", len);
// 	len = printf("%i\n", i);
// 	printf ("len 2 : %d\n\n\n", len);
// 	/*UNSIGNED*/
// 	len = ft_printf(1, "%u\n", u);
// 	printf ("len 1 : %d\n", len);
// 	len = printf("%u\n", u);
// 	printf ("len 2 : %d\n\n\n", len);
// 	/*hex*/
// 	len = ft_printf(1, "%x\n", x);
// 	printf ("len 1 : %d\n", len);
// 	len = printf("%x\n", x);
// 	printf ("len 2 : %d\n\n\n", len);
// 	/*HEX*/
// 	len = ft_printf(1, "%X\n", X);
// 	printf ("len 1 : %d\n", len);
// 	len = printf("%X\n", X);
// 	printf ("len 2 : %d\n\n\n", len);
// 	/*PERC*/
// 	len = ft_printf(1, "%% %% %%\n");
// 	printf ("len 1 : %d\n", len);
// 	len = printf("%% %% %%\n");
// 	printf ("len 2 : %d\n\n\n", len);
// 	return (0);
// }
