/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:44:48 by aconciar          #+#    #+#             */
/*   Updated: 2024/06/20 18:59:57 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_handle_variable(char *input, t_data *data, char *output, int *j)
{
	char	*var_name;
	char	*value;
	int		var_len;

	var_len = 0;
	while (ft_isalnum(input[var_len]) || input[var_len] == '_'
		|| input[var_len] == '?')
		var_len++;
	if (ft_isdigit(input[0]))
		var_len = 1;
	var_name = (char *)malloc(sizeof(char) * (var_len + 1));
	var_name = ft_strncpy(var_name, input, var_len);
	value = ft_getenv(data, var_name, data->envp);
	if (value)
	{
		output = ft_strcpy(output + *j, value);
		*j += ft_strlen(value);
	}
	ft_free(var_name);
	ft_free(value);
	return (var_len);
}

static char	*ft_get_exit_status_size(char *str)
{
	int		i;
	int		len;
	char	*var_name;

	i = 0;
	len = 0;
	len++;
	while (ft_isalnum(str[len]) || str[len] == '_')
		len++;
	var_name = (char *)malloc(sizeof(char) * (len + 1));
	if (!var_name)
		return (NULL);
	while (ft_isalnum(str[i]) || str[i] == '_' || str[i] == '?')
	{
		var_name[i] = str[i];
		i++;
	}
	var_name[i] = '\0';
	return (var_name);
}

static char	*ft_get_var_name(char *str)
{
	int		i;
	int		len;
	char	*var_name;

	i = 0;
	len = 0;
	if (str[0] == '?')
		return (ft_get_exit_status_size(str));
		
	while (ft_isalnum(str[len]) || str[len] == '_')
		len++;
	if (ft_isdigit(str[0]))
		len = 1;
	var_name = (char *)malloc(sizeof(char) * (len + 1));
	if (!var_name)
		return (NULL);
	if (ft_isdigit(str[0]))
		return (ft_strncpy(var_name, str, 1));
	while (ft_isalnum(str[i]) || str[i] == '_')
	{
		var_name[i] = str[i];
		i++;
	}
	var_name[i] = '\0';
	return (var_name);
}

static int	ft_size_env(char *input, t_data *data, bool expand)
{
	int		size;
	int		i;
	char	*var_val;
	char	*var_name;

	size = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && expand == true)
		{
			var_name = ft_get_var_name(&input[i + 1]);
			var_val = ft_getenv(data, var_name, data->envp);
			size += ft_strlen(var_val);
			ft_free(var_name);
			ft_free(var_val);
		}
		else
			size++;
		i++;
	}
	return (size);
}

char	*ft_expand(char *input, t_data *data, bool expand)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	output = (char *)malloc(sizeof(char) * (ft_size_env(input, data, expand) + 1));
	if (!output)
		return (NULL);
	while (input[i])
	{
		if (input[i] == '$' && expand == true)
		{
			i += ft_handle_variable(&input[i + 1], data, output, &j);
			i++;
		}
		else
			output[j++] = input[i++];
	}
	output[j] = '\0';
	return (output);
}
