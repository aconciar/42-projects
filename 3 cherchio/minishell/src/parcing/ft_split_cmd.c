/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:37:26 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 18:28:33 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_find_new_word(t_data *data, t_token *mat, int *flag)
{
	char *value;

	if (ft_find_token(mat->value, data->envp, mat->type) == T_RED_HDOC)
		*flag = 3;
	if (mat->type != T_SEP && *flag == 1)
	{
		value = ft_new_word(mat->value, data, false);
		*flag = 0;
	}
	else
	{
		value = ft_new_word(mat->value, data, true);
		*flag -= 1;
	}
	return (value);
}

t_token	*ft_split_cmd(char *str, t_data *data)
{
	t_token	*mat;
	t_token	*cmd;
	t_token	*tmp;
	char	*value;
	int		flag;

	flag = 0;
	cmd = NULL;
	mat = ft_split_mini(str);
	tmp = mat;
	while (mat)
	{
		value = ft_find_new_word(data, mat, &flag);
		if (value != NULL)
			ft_list_addback(&cmd, ft_create_node(mat->type, value));
		else
			ft_list_addback(&cmd, ft_create_node(T_WORD, NULL));
		mat = mat->next;
		ft_free(value);
	}
	mat = tmp;
	ft_free_list(mat);
	return (cmd);
}
