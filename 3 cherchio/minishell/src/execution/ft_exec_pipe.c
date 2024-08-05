/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:23:53 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 15:16:12 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_exec(t_data **exec)
{
	ft_free_matrix((*exec)->envp);
	ft_free_matrix((*exec)->export);
	ft_free((*exec)->path_ok);
	ft_free_matrix((*exec)->cmd);
	ft_free_matrix((*exec)->path);
	free(*exec);
}

static void	ft_child_process(t_data **exec, t_token **token)
{
	int	ret;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if ((*exec)->type == T_BUILTIN)
	{
		ret = ft_builtin(exec);
		ft_list_clear(token, free);
		ft_free_envp(&(*exec)->cmd);
		ft_free_data(exec);
		free(*exec);
		exit (ret);
	}
	if (execve((*exec)->path_ok, (*exec)->cmd, (*exec)->envp) == -1)
	{
		ft_list_clear(token, free);
		ft_free_exec(exec);
		perror("Error: ");
		if (errno == 13)
			exit (126);
		else if (errno == 2)
			exit (127);
		else
			exit (errno);
	}
}

pid_t	ft_exec_pipe(t_data **exec, t_token *token)
{
	int		fd[2];
	pid_t	pid_child;

	if (pipe(fd) == -1)
		return (ft_printf(2, "Error pipe\n"));
	if ((*exec)->redirect_out == true)
	{
		if (dup2((*exec)->outfile, STDOUT_FILENO) == -1)
			return (-1);
	}
	else
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return (-1);
	pid_child = fork();
	if (pid_child == -1)
		exit (ft_printf(2, "Error pid\n"));
	if (pid_child == 0)
		ft_child_process(exec, &token);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return (pid_child);
}
