/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:07:41 by andrea            #+#    #+#             */
/*   Updated: 2024/02/12 17:24:37 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(int *fd, char **argv, char **envp, int infile)
{
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

void	ft_open_files(int *infile, int *outfile, char *argv[])
{
	*infile = open(argv[1], O_RDONLY, 0777);
	if (*infile == -1)
		exit (3);
	*outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (*outfile == -1)
		exit (3);
	dup2(*infile, STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		outfile;
	int		infile;
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (ft_putstr_fd("Error\n", 2), 1);
		pid = fork();
		ft_open_files(&infile, &outfile, argv);
		if (pid == -1)
			return (ft_putstr_fd("Error\n", 2), 2);
		if (pid == 0)
			ft_child_process(fd, argv, envp, infile);
		waitpid(pid, NULL, 0);
		ft_parent_process(fd, argv, envp, outfile);
	}
	else
		return (ft_putstr_fd("Error Invalid Arguments\n", 2), 3);
	close(infile);
	close(outfile);
	return (0);
}
