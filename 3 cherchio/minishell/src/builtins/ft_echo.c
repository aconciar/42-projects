/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:58:22 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 15:32:27 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_newline(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	else
		return (1);
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_echo(char **cmd)
{
	int	i;
	int	n;
	int	j;

	n = 0;
	i = 1;
	if (cmd[i] == NULL)
	{
		ft_printf(1, "\n");
		return ;
	}
	if (ft_is_newline(cmd[i]) == 0)
		n = 1;
	while (cmd[i] && ft_is_newline(cmd[i]) == 0)
		i++;
	j = i;
	while (cmd[i])
	{
		if (i != j)
			ft_printf(1, " ");
		ft_printf(1, "%s", cmd[i]);
		i++;
	}
	if (n == 0)
		ft_printf(1, "\n");
}
