/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize_mini.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:41:49 by andrea            #+#    #+#             */
/*   Updated: 2024/06/20 17:48:33 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_separator(char *str, int i, t_token **new)
{
	int	end;

	end = i;
	while (str[end] && ft_isspace(str[end]))
		end++;
	ft_list_addback(new, ft_create_node(T_SEP, " "));
	return (end - i);
}

static int	ft_new_word_no_quotes(char *str, int i, t_token **new)
{
	int		end;
	char	*tmp;
	char	c;

	end = i;
	while (str[end] && !ft_isspace(str[end]))
	{
		if (str[end] == '\"' || str[end] == '\'')
		{
			c = str[end];
			end++;
			while (str[end] && str[end] != c)
				end++;
		}
		end++;
	}
	tmp = ft_substr(str, i, end - i);
	ft_list_addback(new, ft_create_node(T_WORD, tmp));
	ft_free(tmp);
	return (end - i);
}

static int	ft_new(char *str, int i, t_token **new, char c)
{
	int		end;
	char	*tmp;

	end = i;
	if (str[end] == '\"' || str[end] == '\'')
		end++;
	while (str[end] && str[end] != c)
		end++;
	if (str[end] == '\"' || str[end] == '\'')
		end++;
	tmp = ft_substr(str, i, end - i);
	ft_list_addback(new, ft_create_node(T_QUOTES, tmp));
	ft_free(tmp);
	return (end - i);
}

t_token	*ft_split_mini(char *str)
{
	t_token	*new;
	int		i;

	new = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '\"')
			i += ft_new(str, i, &new, '\"');
		else if (str[i] && str[i] == '\'')
			i += ft_new(str, i, &new, '\'');
		else if (str[i] && ft_isspace(str[i]))
			i += ft_separator(str, i, &new);
		else if (str[i])
			i += ft_new_word_no_quotes(str, i, &new);
		if (str[i] == '\0')
			break ;
	}
	return (new);
}
