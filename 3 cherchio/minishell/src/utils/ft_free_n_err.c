/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_n_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:37:43 by fdonati           #+#    #+#             */
/*   Updated: 2024/06/19 22:28:19 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_both(char *str, char *str2)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (str2 != NULL)
	{
		free(str2);
		str2 = NULL;
	}
}

void	ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix != NULL)
	{
		while (matrix[i] != NULL)
		{
			ft_free(matrix[i]);
			matrix[i] = NULL;
			i++;
		}
		free(matrix);
		matrix = NULL;
	}
}

int	ft_free_n_err(char **line, t_token **token, int ret)
{
	if (line != NULL)
	{
		ft_free(*line);
		*line = NULL;
	}
	if (token != NULL)
	{
		ft_list_clear(token, free);
		*token = NULL;
	}
	return (ret);
}

void	ft_free_data(t_data **data)
{
	ft_free_matrix((*data)->envp);
	ft_free_matrix((*data)->export);
}
