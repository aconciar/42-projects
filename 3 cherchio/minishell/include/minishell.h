/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:15:19 by fdonati           #+#    #+#             */
/*   Updated: 2024/06/21 15:40:13 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_RED_IN,
	T_RED_OUT,
	T_RED_APPEND,
	T_RED_HDOC,
	T_BUILTIN,
	T_COMMAND,
	T_LIM,
	T_LIM_QTS,
	T_FD,
	T_QUOTES,
	T_SEP
}	t_token_type;

typedef struct s_data
{
	char	**export;
	char	**envp;
	char	**cmd;
	char	**path;
	char	*path_ok;
	int		type;
	int		infile;
	int		outfile;
	int		pipe_nbr;
	int		cmd_nbr;
	int		original_stdin;
	int		original_stdout;
	bool	redirect_out;
	bool	here_doc;
	bool	status_changed;
	int		exit_status;
	bool	exit;
	bool	execute;
}				t_data;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}			t_token;

typedef struct s_split
{
	char	**env;
	int		i;
	int		j;
	char	c;
	int		start;
	bool	exp;
}			t_split;

void			ft_free_envp(char ***envp);
char			**ft_copy_envp(char **envp);
void			ft_sort_env(char **environ);
int				ft_is(char *line, char *str);
t_token			*ft_tokenize(char *line, t_data *data);
int				ft_open_quotes(char *str);
int				ft_is_builtin(char *line);
t_token_type	ft_find_token(char *value, char **envp, t_token_type type);
t_token			*ft_split_cmd(char *str, t_data *data);
char			**ft_split_echo(char *str, char c);
t_token			*ft_split_mini(char *str);
int				ft_is_command(char *cmd, char **envp);
int				ft_builtins_no_process(t_token *cmd, t_data **data);
void			ft_cd(t_data **exec, t_token *cmd);
void			ft_set_export(t_data **exec, t_token *cmd, int i, char *var);
int				ft_init_var(char **env, char **exp, char **var, t_data **exec);
void			ft_unset(t_data **exec, t_token *cmd);
void			ft_set_exst_to_one(t_data **exec, char *str);
int				ft_exit(t_token *cmd, t_data **data);
int				ft_parse_var(char *var);
char			*ft_getenv(t_data *data, char *env_var, char **envp);
void			ft_setenv(t_data **data, char *env_var, char *value, int flag);
void			ft_setenv_export(t_data **data, char *env_var, char *value, int flag);
void			ft_unsetenv(t_data **data, char *env_var, int f);
void			ft_unsetenv_export(t_data **data, char *env_var, int f);
t_token			*ft_parsing(t_token *token);
char			*ft_fd(t_token **token, int *t, t_token_type *type, char *tmp);
char			**ft_create_cmd(t_token *token);
int				ft_command(t_token *token, t_data **data);
int				ft_syntax_error(t_token *token);
int				ft_execute_token(t_token *tmp, t_data **data, t_token *token);
pid_t			ft_execute(t_token *tmp, t_data **data, t_token *token);
int				ft_redirect(t_token *token, t_data ***data);
int				ft_open_files(t_token *token, t_data ***data, int flag);
int				ft_is_red(int type);
pid_t			ft_exec_pipe(t_data **exec, t_token *token);
pid_t			ft_exec_pipezero(t_data **exec, t_token **token);
void			ft_original_std(t_data **data);
int				is_path(char *str);
char			**ft_path(char **envp);
char			*ft_find_path(char **path, char *argv);
int				ft_builtin(t_data **exec);
void			ft_echo(char **cmd);
int				ft_matlen(char **mat);
char			**ft_realloc(char **mat, int i);
char			**ft_matjoin(char **mat, char *str);
int				ft_free_n_err(char **line, t_token **token, int ret);
void			ft_free(char *str);
void			ft_free_both(char *str, char *str2);
void			ft_free_data(t_data **data);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strcpy(char *dest, char *src);
int				ft_iterate(char *str, int (*f)(int));
char			*ft_expand(char *input, t_data *data, bool expand);
char			*ft_new_word(char *input, t_data *data, bool expand);
void			ft_signal_hc(int signum);
void			ft_signal(int signum);
void			ft_signal_cmd(int signum);
void			ft_print_token(t_token *token);
void			ft_set_export_process(t_data **exec, int i, char *var, int a);
void			ft_cd_process(t_data **exec);
void			ft_unset_process(t_data **exec);
int				ft_exit_process(t_data **data);

t_token			*ft_create_node(t_token_type type, char *value);
t_token			*ft_create_list(int argc, char **argv);
t_token			*ft_list_last(t_token *list);
int				ft_list_size(t_token *list);
void			ft_free_list(t_token *list);
void			ft_list_addfront(t_token **list, t_token *new);
void			ft_list_addback(t_token **list, t_token *new);
int				ft_list_find_node(t_token *list, t_token_type type);
void			ft_free_matrix(char **matrix);
void			ft_list_clear(t_token **lst, void (*del)(void*));
void			ft_listdel_one(t_token *lst, void (*del)(void*));

extern int	g_exit_status;

# define PROMPT "minishell$ "

#endif
