/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:23:07 by aconciar          #+#    #+#             */
/*   Updated: 2023/11/02 19:14:49 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*scroll(char *str)
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
	dst = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dst)
		return (NULL);
	i++;
	while (str[i])
		dst[j++] = str[i++];
	dst[j] = '\0';
	free(str);
	return (dst);
}

char	*get_linea(char *str)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		temp[i] = str[i];
	if (str[i] == '\n')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*readline(int fd, char *str, int cont)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (buf);
		return (NULL);
	}
	while (cont > 0 && !ft_strchr(str, '\n'))
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
		str = ft_strjoin(str, buf);
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

	cont = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = readline(fd, str, cont);
	if (!str)
	{
		free (str);
		return (NULL);
	}
	line = get_linea(str);
	str = scroll(str);
	if (str[0] == '\0')
		free(str);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;

	i = 6;
	fd = open("map.txt", O_RDONLY);
	while (i > 0)
	{
		char	*temp = get_next_line(fd);
		printf("%s",temp);
		free(temp);
		i--;
	}
	return (0);
}
