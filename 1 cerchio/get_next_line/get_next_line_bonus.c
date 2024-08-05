/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:20:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/03/15 18:42:43 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	{
		free(dst);
		return (NULL);
	}
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
	{
		free(temp);
		return (NULL);
	}
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
	static char	*str[1024];
	int			cont;

	cont = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = readline(fd, str[fd], cont);
	if (!str[fd])
	{
		free (str[fd]);
		return (NULL);
	}
	line = get_linea(str[fd]);
	str[fd] = scroll(str[fd]);
	if (!str[fd])
		free(str[fd]);
	return (line);
}

int	main(void)
{
	int		fd;
	int		fd2;
	int		i = 10;

	fd = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	while (i > 0)
	{
		printf("risultato finale 1: %s", get_next_line(fd));
		printf("risultato finale 1: %s", get_next_line(fd2));
		i--;
	}
	return (0);
}
