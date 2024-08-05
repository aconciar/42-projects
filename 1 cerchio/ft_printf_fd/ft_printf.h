/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:35:58 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/22 17:26:34 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

int	ft_printf(int fd, const char *str, ...);
int	ft_char(char c, int fd);
int	ft_dec(int n, int fd);
int	ft_string(char *str, int fd);
int	n_sp(int nbr, int len);
int	ft_putnbr_base(int nbr, char *base, int fd);
int	ft_unsigned(unsigned int n, int fd);
int	ft_ptr_void(uint64_t ptr, int fd);
int	putnbr_hex(unsigned int nbr, char *base, int fd);
int	ft_strcmp(const char *s1, const char *s2);

#endif