/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:43:26 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/19 17:05:39 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	ft_signal_cmd(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf(1, "\n");
		g_exit_status = 130;
	}
}

void	ft_signal(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf(1, "\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = 130;
	}
	if (signum == SIGQUIT)
	{
		ft_printf(1, "Quit: 3\n");
		g_exit_status = 131;
	}
}

void	ft_signal_hc(int signum)
{
	if (signum == SIGINT)
	{
		close(STDIN_FILENO);
		g_exit_status = 130;
		ft_printf(1, "\n");
	}
}
