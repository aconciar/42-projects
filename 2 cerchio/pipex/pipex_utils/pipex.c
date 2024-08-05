/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:07:41 by andrea            #+#    #+#             */
/*   Updated: 2024/04/08 18:11:58 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process(char *cmd, char **envp, int outfile, int check)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error("Error2\n");
	pid = fork();
	if (pid == -1)
		ft_error("Error\n");
	if (pid == 0)
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
		waitpid(pid, NULL, 0);
	}
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
	int		outfile;
	int		infile;
	int		i;

	if (argc == 5)
	{
		i = 1;
		ft_open_files(&infile, &outfile, argv);
		while (++i < argc - 1)
			ft_process(argv[i], envp, outfile, argc - i - 2);
		close(infile);
		close(outfile);
	}
	else
		ft_error("Error Invalid Arguments\n");
	return (0);
}
