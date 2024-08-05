/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:56:59 by aconciar          #+#    #+#             */
/*   Updated: 2024/03/11 18:59:35 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_child_process(char *cmd, char **envp, int outfile, int check)
{
	pid_t	pid_child;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("Error2\n");
	pid_child = fork();
	if (pid_child == -1)
		ft_error("Error\n");
	if (pid_child == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execute(cmd, envp);
	}
	else if (check == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		ft_execute(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid_child, NULL, 0);
	}
}

void	ft_open_files(int *infile, int *outfile, char *argv[], int argc)
{
	*infile = open(argv[1], O_RDONLY, 0777);
	if (*infile == -1)
		ft_error("Error7\n");
	*outfile = open(argv[argc], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (*outfile == -1)
		ft_error("Error3\n");
	dup2(*infile, STDIN_FILENO);
}

void	ft_here_doc(char *limiter, int argc)
{
	pid_t	pid_hd;
	int		fd[2];
	char	*line;

	if (argc < 6 && pipe(fd) == -1)
		ft_error("Error1\n");
	pid_hd = fork();
	if (pid_hd == 0)
	{
		close(fd[0]);
		while (1)
		{
			line = get_next_line(0);
			if (ft_strcmp(line, limiter) == 0)
				exit(0);
			ft_putstr_fd(line, fd[1]);
			ft_putstr_fd("\n", fd[1]);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		outfile;
	int		infile;
	int		i;

	if (argc >= 5)
	{
		i = 1;
		if (ft_strcmp(argv[1], "here_doc") == 0)
		{
			outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0777);
			if (outfile == -1)
				ft_error("Error0\n");
			ft_here_doc(argv[2], argc);
			i++;
		}
		else
			ft_open_files(&infile, &outfile, argv, argc - 1);
		while (++i < argc - 1)
			ft_child_process(argv[i], envp, outfile, argc - i - 2);
		close(outfile);
		close(infile);
	}
	else
		ft_error("Error Invalid Arguments\n");
	return (0);
}
