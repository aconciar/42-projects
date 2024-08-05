/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:23:07 by aconciar          #+#    #+#             */
/*   Updated: 2024/07/07 16:45:00 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*scroll(char *str)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dst = (char *)malloc(sizeof(char) * (ft_strlengnl(str) - i + 1));
	if (!dst)
		return (NULL);
	i++;
	while (str[i])
		dst[j++] = str[i++];
	dst[j] = '\0';
	free(str);
	return (dst);
}

static char	*get_linea(char *str)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		temp[i] = str[i];
	temp[i] = '\0';
	return (temp);
}

static char	*readline(int fd, char *str, int cont)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (buf);
		return (NULL);
	}
	while (cont > 0 && !ft_strchrgnl(str, '\n'))
	{
		cont = read(fd, buf, BUFFER_SIZE);
		if (cont == -1)
		{
			free(buf);
			return (0);
		}
		else if (cont == 0)
			break ;
		buf[cont] = '\0';
		str = ft_strjoingnl(str, buf);
		if (!str)
			return (NULL);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	int			cont;

	if (fd == -42)
		free(str);
	cont = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = readline(fd, str, cont);
	if (!str)
	{
		free (str);
		return (NULL);
	}
	line = get_linea(str);
	str = scroll(str);
	return (line);
}
