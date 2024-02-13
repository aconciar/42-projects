/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:56:59 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/12 19:24:48 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (7);
}

void	ft_child_process(int *fd, char **argv, char **envp, int infile, int pid)
{
	if (pipe(fd) == -1)
		ft_error("Error\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error\n");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	ft_execute(argv[2], envp);
}

void	ft_parent_process(int *fd, char **argv, char **envp, int outfile)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	ft_execute(argv[3], envp);
}

void	ft_open_files(int *infile, int *outfile, char *argv[], int argc)
{
	*infile = open(argv[1], O_RDONLY, 0777);
	if (*infile == -1)
		ft_error("Error\n");
	*outfile = open(argv[argc], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (*outfile == -1)
		ft_error("Error\n");
	dup2(*infile, STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		outfile;
	int		infile;
	pid_t	pid;
	int		i;

	if (argc >= 5)
	{
		ft_open_files(&infile, &outfile, argv, argc - 1);
		i = argc - 5;
		while (i > 0)
		{
			if (pipe(fd) == -1)
				ft_error("Error\n");
			pid = fork();
			if (pid == -1)
			ft_error("Error\n");
			ft_child_process(fd, argv, envp, infile, pid);
			i--;
		}
		ft_parent_process(fd, argv, envp, outfile);
	}
	else
			ft_error("Error Invalid Arguments\n");
	close(infile);
	close(outfile);
	return (0);
}
