/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:04:20 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 18:17:54 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

static int	ft_valid_line(t_data *data, char *line, t_token *token)
{
	add_history(line);
	token = ft_tokenize(line, data);
	if (token == NULL)
		return (ft_free_n_err(&line, &token, 0));
	else if (ft_builtins_no_process(token, &data) == 0)
	{
		if (data->status_changed == true || data->execute == false)
			return (ft_free_n_err(&line, &token, 0));
		signal(SIGINT, ft_signal_cmd);
		ft_free_n_err(&line, NULL, 0);
		data->exit_status = ft_command(token, &data);
		ft_free_n_err(NULL, &token, 0);
		return (0);
	}
	else
		return (ft_free_n_err(&line, &token, 1));
}

static int	ft_readline(t_token	*token, t_data *data)
{
	char	*line;

	while (1)
	{
		data->execute = true;
		data->status_changed = false;
		signal(SIGINT, ft_signal);
		signal(SIGQUIT, SIG_IGN);
		line = readline("minishell$ ");
		if (g_exit_status != 0)
		{
			data->exit_status = g_exit_status;
			g_exit_status = 0;
		}
		if (!line)
		{
			ft_printf(1, "exit\n");
			return (data->exit_status);
		}
		if (line[0] != '\0')
			if (ft_valid_line(data, line, token) == 1)
				break ;
	}
	return (data->exit_status);
}

int	main(int argc, char **argv, char **environ)
{
	t_token	*token;
	t_data	*data;
	int		ret;

	(void)argc;
	(void)argv;
	token = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	data->envp = ft_copy_envp(environ);
	data->export = ft_copy_envp(environ);
	data->exit_status = 0;
	data->exit = false;
	ft_sort_env(data->export);
	ft_readline(token, data);
	ret = data->exit_status;
	ft_free_data(&data);
	free(data);
	return (ret);
}
