/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:46:59 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/21 18:29:29 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		ft_printf(2, "type: %d, value: %s\n", tmp->type, tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int	ft_iterate(char *str, int (*f)(int))
{
	int	i;

	i = 0;
	while (f(str[i]) == 1)
		i++;
	while (str[i])
	{
		if (f(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_set_exst_to_one(t_data **exec, char *str)
{
	if (str != NULL)
		ft_printf(2, "%s\n", str);
	(*exec)->exit_status = 1;
	(*exec)->status_changed = true;
}

int	ft_is(char *line, char *str)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i])
	{
		while (line[i] && str[y] && line[i] == str[y])
		{
			i++;
			y++;
		}
		if (str[y] == '\0')
			return (0);
	}
	return (1);
}

int	ft_matlen(char **mat)
{
	int	y;

	y = 0;
	while (mat[y])
		y++;
	return (y);
}

char	**ft_matjoin(char **mat, char *str)
{
	int		i;
	char	**new;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (ft_matlen(mat) + 2));
	if (!new)
		return (NULL);
	while (mat[i])
	{
		new[i] = ft_strdup(mat[i]);
		i++;
	}
	ft_free_matrix(mat);
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	return (new);
}
