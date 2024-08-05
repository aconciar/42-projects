/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:41:49 by andrea            #+#    #+#             */
/*   Updated: 2024/06/20 18:17:51 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_expanded(char *input, char *out, t_split **split, t_data *data)
{
	int		k;
	char	temp[1024];
	char	*expanded;

	k = 0;
	while (input[(*split)->i] && input[(*split)->i] != (*split)->c)
		temp[k++] = input[(*split)->i++];
	temp[k] = '\0';
	expanded = ft_expand(temp, data, true);
	if (out == NULL)
		out = ft_strdup(expanded);
	else if (out[ft_strlen(out) - 1] == '$')
	{
		ft_free(out);
		out = ft_strdup(expanded);
	}
	else
		out = ft_strfjoin(out, expanded);
	(*split)->j += ft_strlen(expanded);
	ft_free(expanded);
	return (out);
}

static char	*ft_expanded_no_quotes(char *str, char *o, t_split **spl, t_data *d)
{
	int		k;
	char	temp[1024];
	char	*expanded;

	k = 0;
	while (str[(*spl)->i] && str[(*spl)->i] != '\"' && str[(*spl)->i] != '\'')
		temp[k++] = str[(*spl)->i++];
	temp[k] = '\0';
	expanded = ft_expand(temp, d, (*spl)->exp);
	if (o == NULL)
		o = ft_strdup(expanded);
	else if (o[ft_strlen(o)] == '$')
	{
		ft_free(o);
		o = ft_strdup(expanded);
	}
	else
		o = ft_strfjoin(o, expanded);
	(*spl)->j += ft_strlen(expanded);
	ft_free(expanded);
	return (o);
}

char	*ft_expanded_s_quotes(char *in, char *out, t_split **split)
{
	int		start;
	char	*tmp;

	(*split)->start = (*split)->i;
	start = (*split)->start;
	while (in[(*split)->i] && in[(*split)->i] != (*split)->c)
		(*split)->i++;
	(*split)->i--;
	if (out == NULL)
		out = ft_substr(in, start, (*split)->i - start + 1);
	else if (out[ft_strlen(out) - 1] == '$')
	{
		ft_free(out);
		out = ft_substr(in, start, (*split)->i - start + 1);
	}
	else
	{
		tmp = ft_substr(in, start, (*split)->i - start + 1);
		out = ft_strfjoin(out, tmp);
		free(tmp);
	}
	(*split)->i++;
	return (out);
}

static void	ft_init_split(t_split **split, bool expand)
{
	(*split)->i = 0;
	(*split)->j = 0;
	(*split)->exp = expand;
}

char	*ft_new_word(char *input, t_data *data, bool expand)
{
	char	*output;
	t_split	*split;

	split = (t_split *)malloc(sizeof(t_split));
	ft_init_split(&split, expand);
	output = NULL;
	while (input[split->i])
	{
		if (input[split->i] == '\'' || input[split->i] == '\"')
		{
			split->c = input[split->i++];
			if (split->c == '\"' && split->exp == true)
				output = ft_expanded(input, output, &split, data);
			else
				output = ft_expanded_s_quotes(input, output, &split);
			split->i++;
		}
		else
			output = ft_expanded_no_quotes(input, output, &split, data);
		if (input[split->i] == '\0')
			break ;
	}
	free(split);
	return (output);
}
